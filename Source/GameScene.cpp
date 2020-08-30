// Precompiled Headers
#include "stdafx.h"

#include "GameScene.h"

GameScene::GameScene() {
	// Top-down 2D
	if (!m_World) {
		b2Vec2 Gravity(0.0f, 0.0f);
		m_World = new b2World(Gravity);
		m_World->SetContactListener(&m_myContactListener);
	}
}

GameScene::~GameScene() {
	if (m_World) { delete(m_World); m_World = nullptr; }
}

void GameScene::LoadFromFile(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		// PlaceHolder Scene, for testing;
		LoadTerrain("Stage1_Terrain.txt");

		b2Body* PlayerBody = CreateBody(2, 2, 1, 1, false);

		m_Player = Player(0, "PLAYER", "PLAYER_IDLE_DOWN", PlayerBody);

		b2Body* EnemyBody = CreateBody(5, 5, 1, 1, false);

		Enemy* Skele = new Enemy(0, "SKELE", "SKELE", EnemyBody);

		m_Enemies.push_back(Skele);

		// Close FileStream
		fclose(FileStream);
	}
}

void GameScene::LoadTerrain(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;
		int iSizeX, iSizeY;

		iVal = fscanf(FileStream, "#SIZE %d %d\n", &iSizeX, &iSizeY);

		for (int i = 0; i < iSizeY; i++) {
			for (int k = 0; k < iSizeX; k++) {
				int iTerrainVal = 0;
				iVal = fscanf(FileStream, "%d", &iTerrainVal);

				if (iTerrainVal == 0) {
					Ground NewGround("DUNGEON_GROUND", k, i);
					m_GroundTiles.push_back(NewGround);
				}
				else if (iVal == 1) {
					b2Body* WallBody = CreateBody(k, i, 1, 1, true);

					Wall NewWall(0, "WALL", "DUNGEON_WALL", WallBody);

					m_Walls.push_back(NewWall);
				}
			}
		}

		fclose(FileStream);
	}
}

b2Body* GameScene::CreateProjectile(float fPositionX, float fPositionY, float fVelocityX, float fVelocityY) {
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(fPositionX / PIXELS_METERS, fPositionY / PIXELS_METERS);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;

	b2Body* PhysicsBody = m_World->CreateBody(&BodyDef);

	b2PolygonShape BodyShape;
	BodyShape.SetAsBox((10 / 2) / PIXELS_METERS, (10 / 2) / PIXELS_METERS); // Takes 1/2 Width and 1/2 Height

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &BodyShape;
	FixtureDef.isSensor = true;

	PhysicsBody->CreateFixture(&FixtureDef);

	PhysicsBody->SetLinearVelocity(b2Vec2(fVelocityX, fVelocityY));

	return PhysicsBody;
}

b2Body* GameScene::CreateSensor(float fPositionX, float fPositionY, float fSizeX, float fSizeY) {
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(fPositionX / PIXELS_METERS, fPositionY / PIXELS_METERS);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;

	b2Body* PhysicsBody = m_World->CreateBody(&BodyDef);

	b2PolygonShape BodyShape;
	BodyShape.SetAsBox(((fSizeX) / 2) / PIXELS_METERS, ((fSizeY) / 2) / PIXELS_METERS); // Takes 1/2 Width and 1/2 Height

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &BodyShape;
	FixtureDef.isSensor = true;

	PhysicsBody->CreateFixture(&FixtureDef);

	return PhysicsBody;
}

b2Body* GameScene::CreateBody(int iX, int iY, int iSizeX, int iSizeY, bool bStatic)
{
	float fPositionX = TILE_SIZE * iX, fPositionY = TILE_SIZE * iY;
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(fPositionX / PIXELS_METERS, fPositionY / PIXELS_METERS);
	if (bStatic) {
		BodyDef.type = b2_staticBody;
	}
	else {
		BodyDef.type = b2_dynamicBody;
	}
	BodyDef.fixedRotation = true;

	b2Body* PhysicsBody = m_World->CreateBody(&BodyDef);

	b2PolygonShape BodyShape;
	BodyShape.SetAsBox(((TILE_SIZE * iSizeX) / 2) / PIXELS_METERS, ((TILE_SIZE * iSizeY) / 2) / PIXELS_METERS); // Takes 1/2 Width and 1/2 Height

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &BodyShape;

	PhysicsBody->CreateFixture(&FixtureDef);

	return PhysicsBody;
}

void GameScene::Update(float fDeltaTime) {
	// Update Input
	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::DOWN)) {
		m_Player.Move(fDeltaTime, 0);
	}
	else {
		m_Player.Stop(fDeltaTime, 0);
	}

	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::UP)) {
		m_Player.Move(fDeltaTime, 1);
	}
	else {
		m_Player.Stop(fDeltaTime, 1);
	}

	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::LEFT)) {
		m_Player.Move(fDeltaTime, 2);
	}
	else {
		m_Player.Stop(fDeltaTime, 2);
	}

	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::RIGHT)) {
		m_Player.Move(fDeltaTime, 3);
	}
	else {
		m_Player.Stop(fDeltaTime, 3);
	}

	if (Keyboard::GetInstance()->GetKeyPressed(Keyboard::ATTACK)) {
		m_Player.MeleeAttack();
		SoundManager::GetInstance()->PlayEffectByName("PLAYER_ATTACK");
	}

	m_Player.Update(fDeltaTime);

	for (int i = 0; i < m_Enemies.size(); i++) {
		m_Enemies.at(i)->Update(fDeltaTime);
	}

	m_World->Step(fDeltaTime, 4, 2);
}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	for (int i = 0; i < m_GroundTiles.size(); i++) {
		m_GroundTiles.at(i).Render(MainWindow);
	}
	
	for (int i = 0; i < m_Walls.size(); i++) {
		m_Walls.at(i).Render(MainWindow);
	}

	for (int i = 0; i < m_Enemies.size(); i++) {
		m_Enemies.at(i)->Render(MainWindow);
	}

	m_Player.Render(MainWindow);
}