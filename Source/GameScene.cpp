// Precompiled Headers
#include "stdafx.h"

#include "GameScene.h"

GameScene::GameScene() {
	// Top-down 2D
	if (!m_World) {
		b2Vec2 Gravity(0.0f, 0.0f);
		m_World = new b2World(Gravity);
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

		b2Body* PlayerBody = CreateBody(0, 0, 1, 1, false);

		m_Player = Player(0, "PLAYER", "PLAYER_IDLE_DOWN", PlayerBody);

		for (int i = 0; i < 20; i++) {
			for (int k = 0; k < 20; k++) {
				Ground NewGround("DUNGEON_GROUND", k, i);
				m_GroundTiles.push_back(NewGround);
			}
		}

		b2Body* WallBody = CreateBody(1, 1, 1, 1, true);

		m_Wall = Wall(0, "WALL", "DUNGEON_WALL", WallBody);

		// Close FileStream
		fclose(FileStream);
	}
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
	if (Keyboard::GetKey(Keyboard::UP)) {
		m_Player.Move(fDeltaTime, 1);
	}
	else {
		m_Player.Stop(fDeltaTime, 1);
	}
	if (Keyboard::GetKey(Keyboard::DOWN)) {
		m_Player.Move(fDeltaTime, 0);
	}
	else {
		m_Player.Stop(fDeltaTime, 0);
	}
	if (Keyboard::GetKey(Keyboard::LEFT)) {
		m_Player.Move(fDeltaTime, 2);
	}
	else {
		m_Player.Stop(fDeltaTime, 2);
	}
	if (Keyboard::GetKey(Keyboard::RIGHT)) {
		m_Player.Move(fDeltaTime, 3);
	}
	else {
		m_Player.Stop(fDeltaTime, 3);
	}

	m_Player.Update(fDeltaTime);
	m_Wall.Update(fDeltaTime);

	m_World->Step(fDeltaTime, 4, 2);
}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	for (int i = 0; i < m_GroundTiles.size(); i++) {
		m_GroundTiles.at(i).Render(MainWindow);
	}

	m_Wall.Render(MainWindow);

	m_Player.Render(MainWindow);
}