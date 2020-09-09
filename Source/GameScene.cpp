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
	if (m_World) { delete(m_World); }
	if (playerGUI) {
		delete (playerGUI);
		playerGUI = nullptr;
	}
	if (score) {
		delete score;
		score = nullptr;
	}
}

void GameScene::LoadFromFile(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		// PlaceHolder Scene, for testing;
		LoadTerrain("Stage1_Terrain.txt");

		b2Body* PlayerBody = CreateBody(5, 5, 1, 1, false);

		m_Player = Player(0, "PLAYER", "PLAYER_IDLE_DOWN", PlayerBody);

		b2Body* EnemyBody1 = CreateBody(16, 8, 1, 1, false);
		b2Body* EnemyBody2 = CreateBody(8, 8, 1, 1, false);
		b2Body* EnemyBody3 = CreateBody(8, 16, 1, 1, false);

		Enemy* Skele1 = new Enemy(0, "SKELE", "SKELE", EnemyBody3);

		Enemy* Skele2 = new Enemy(0, "SKELE", "SKELE", EnemyBody2);


		m_Enemies.push_back(Skele1);
		m_Enemies.push_back(Skele2);

		fclose(FileStream);
	}

	SoundManager::GetInstance()->PlayMusicByName("CELESTIAL");
	this->playerGUI = new PlayerGUI(&(this->m_Player));
	this->score = new Score(&(this->m_Player));
}

void GameScene::LoadTerrain(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;
		int iWidth, iHeight;

		iVal = fscanf(FileStream, "#SIZE WIDTH %d HEIGHT %d\n", &iWidth, &iHeight);
		//ground
		int iVer, iHor;
		char cName[100];
		iVal = fscanf(FileStream, "#GROUND\n");
		iVal = fscanf(FileStream, "NAME: %s VERTICAL: %d HORIZONTAL: %d\n", cName, &iVer, &iHor);
		for (int i = 0; i < iVer; i++)
		{
			for (int j = 0; j < iHor; j++)
			{
				Ground NewGround(cName, j, i);
				m_GroundTiles.push_back(NewGround);
			}
		}

		//wall
		int iWallNum;
		iVal = fscanf(FileStream, "#WALL %d\n", &iWallNum);
		for (int i = 0; i < iWallNum; i++)
		{
			int iAmount;
			char cName[100];
			iVal = fscanf(FileStream, "NAME: %s AMOUNT: %d\n", cName, &iAmount);
			for (int j = 0; j < iAmount; j++)
			{
				int iID, iCorX, iCorY, iVer, iHor;
				iVal = fscanf(FileStream, "ID: %d COR_X: %d COR_Y: %d VERTICAL: %d HORIZONTAL: %d\n", &iID, &iCorX, &iCorY, &iVer, &iHor);

				b2Body* WallBody = CreateWall((float)iCorX, (float)iCorY, iHor, iVer, true);

				Wall *NewWall = new Wall(iID, "WALL", cName, WallBody, iHor, iVer, iCorX, iCorY);

				m_Walls.push_back(NewWall);
			}
		}

		//Decorate
		int iDecorObject;
		iVal = fscanf(FileStream, "#DECORATE %d\n", &iDecorObject);
		for (int i = 0; i < iDecorObject; i++)
		{
			int iAmount;
			char cName[100];
			iVal = fscanf(FileStream, "NAME: %s AMOUNT: %d\n", cName, &iAmount);
			for (int j = 0; j < iAmount; j++)
			{
				int iID, iCorX, iCorY, iVer, iHor;
				iVal = fscanf(FileStream, "ID: %d COR_X: %d COR_Y: %d VERTICAL: %d HORIZONTAL: %d\n", &iID, &iCorX, &iCorY, &iVer, &iHor);

				b2Body* WallBody = CreateWall((float)iCorX, (float)iCorY, 0, 0, true);

				Wall *NewWall = new Wall(iID, "DECOR", cName, WallBody, iHor, iVer, iCorX, iCorY);

				m_Walls.push_back(NewWall);
			}
		}


		fclose(FileStream);
	}
}

b2Body* GameScene::CreateProjectile(float fPositionX, float fPositionY) {
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(fPositionX / PIXELS_METERS, fPositionY / PIXELS_METERS);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;

	b2Body* PhysicsBody = m_World->CreateBody(&BodyDef);

	b2PolygonShape BodyShape;
	BodyShape.SetAsBox((20 / 2) / PIXELS_METERS, (40 / 2) / PIXELS_METERS); // Takes 1/2 Width and 1/2 Height

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &BodyShape;
	FixtureDef.isSensor = true;

	PhysicsBody->CreateFixture(&FixtureDef);

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

b2Body* GameScene::CreateWall(float iX, float iY, int iSizeX, int iSizeY, bool bStatic)
{
	if (iSizeX != 1)
	{
		iX += iSizeX / 2.0f - 0.5f;
	}
	if (iSizeY != 1)
	{
		iY += iSizeY / 2.0f - 0.5f;
	}
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
	BodyShape.SetAsBox(((TILE_SIZE * iSizeX)) / PIXELS_METERS / 2, ((TILE_SIZE * iSizeY)) / PIXELS_METERS / 2); // Takes 1/2 Width and 1/2 Height
	

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &BodyShape;

	PhysicsBody->CreateFixture(&FixtureDef);

	return PhysicsBody;
}

void GameScene::Update(float fDeltaTime) {
	float fPlayerPosX = m_Player.GetPhysicsBody()->GetWorldCenter().x * PIXELS_METERS;
	float fPlayerPosY = m_Player.GetPhysicsBody()->GetWorldCenter().y * PIXELS_METERS;
	//float fDistance = 999999999999;
	MainCamera->SetCameraPosition(fPlayerPosX,fPlayerPosY);

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
	
	if (Mouse::GetInstance()->IsPressed()) {
		b2Vec2 fOrigin = MainCamera->GetCameraCenter();
		float fAngle = GetMouseAngleRadians(fOrigin, b2Vec2(Mouse::GetInstance()->GetPosition().x, Mouse::GetInstance()->GetPosition().y));
		//printf("%f\n", )
		SingleArrow(m_Player.GetPhysicsBody()->GetWorldCenter().x + 1.0f, m_Player.GetPhysicsBody()->GetWorldCenter().y + 1.0f, fAngle);
		SM->PlayEffectByName("PLAYER_ATTACK");
	}

	for (int i = 0; i < m_Enemies.size(); i++) {
		float fEnemyPosX = m_Enemies.at(i)->GetPhysicsBody()->GetWorldCenter().x * PIXELS_METERS;
		float fEnemyPosY = m_Enemies.at(i)->GetPhysicsBody()->GetWorldCenter().y * PIXELS_METERS;
		m_Enemies.at(i)->fDistanceY = sqrt((fPlayerPosY - fEnemyPosY)*(fPlayerPosY - fEnemyPosY));
		m_Enemies.at(i)->fDistanceX = sqrt((fPlayerPosX - fEnemyPosX)*(fPlayerPosX - fEnemyPosX));
		m_Enemies.at(i)->fDistance = sqrt((m_Enemies.at(i)->fDistanceX * m_Enemies.at(i)->fDistanceX) + (m_Enemies.at(i)->fDistanceY *m_Enemies.at(i)->fDistanceY));
		if (m_Enemies.at(i)->fDistance < 500) {
			if (fPlayerPosX <fEnemyPosX && fPlayerPosY < fEnemyPosY) {
					if (m_Enemies.at(i)->fDistance < 70 && (m_Enemies.at(i)->fDistanceX <1 || m_Enemies.at(i)->fDistanceY <1)) {
						m_Enemies.at(i)->Stop(fDeltaTime, 4);
						m_Enemies.at(i)->Move(fDeltaTime, -1);
				}
				else if (m_Enemies.at(i)->fDistanceX < 70) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 1);
				}
				else {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 2);
					m_Enemies.at(i)->Move(fDeltaTime, 1);
				}
			}
			if (fPlayerPosX < fEnemyPosX && fPlayerPosY > fEnemyPosY) {
				if (m_Enemies.at(i)->fDistance < 70 && (m_Enemies.at(i)->fDistanceX <1 || m_Enemies.at(i)->fDistanceY <1)) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, -1);
				}
				else if (m_Enemies.at(i)->fDistanceX < 70) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 0);
				}
				else {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 2);
					m_Enemies.at(i)->Move(fDeltaTime, 0);
				}
			}
			if (fPlayerPosX > fEnemyPosX && fPlayerPosY < fEnemyPosY) {
				if (m_Enemies.at(i)->fDistance < 70 && (m_Enemies.at(i)->fDistanceX <1 || m_Enemies.at(i)->fDistanceY <1)) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, -1);
				}
				else if (m_Enemies.at(i)->fDistanceX < 70) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 1);
				}
				else {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 3);
					m_Enemies.at(i)->Move(fDeltaTime, 1);
				}
			}
			if (fPlayerPosX > fEnemyPosX && fPlayerPosY > fEnemyPosY) {
				if (m_Enemies.at(i)->fDistance < 70 && (m_Enemies.at(i)->fDistanceX <1 || m_Enemies.at(i)->fDistanceY <1)) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, -1);
				}
				else if (m_Enemies.at(i)->fDistanceX < 70) {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 0);
				}
				else {
					m_Enemies.at(i)->Stop(fDeltaTime, 4);
					m_Enemies.at(i)->Move(fDeltaTime, 3);
					m_Enemies.at(i)->Move(fDeltaTime, 0);
				}
			}

		}
		else {
			m_Enemies.at(i)->Stop(fDeltaTime, 4);
			m_Enemies.at(i)->Move(fDeltaTime, -1);
		}
		m_Enemies.at(i)->Update(fDeltaTime);
	}

	
	for (int i = 0; i < m_Projectiles.size(); i++) {
		m_Projectiles.at(i)->Update(fDeltaTime);
	}
	
	m_Player.Update(fDeltaTime);

	m_World->Step(fDeltaTime, 4, 2);
}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	for (int i = 0; i < m_GroundTiles.size(); i++) {
		m_GroundTiles.at(i).Render(MainWindow);
	}
	
	for (int i = 0; i < m_Walls.size(); i++) {
		m_Walls.at(i)->Render(MainWindow);
	}

	for (int i = 0; i < m_Enemies.size(); i++) {
		m_Enemies.at(i)->Render(MainWindow);
}

	for (int i = 0; i < m_Projectiles.size(); i++) {
		m_Projectiles.at(i)->Render(MainWindow);
	}
	m_Player.Render(MainWindow);
	playerGUI->render(MainWindow);
	score->Render(MainWindow);
	//StageClear(MainWindow);
}

float GameScene::GetMouseAngleRadians(b2Vec2 fOrigin, b2Vec2 fTarget) {
	b2Vec2 toTarget = fTarget - fOrigin;
	float fAngle = atan2f(-toTarget.x, toTarget.y);
	return fAngle;
}

void GameScene::SingleShot(float fPositionX, float fPositionY, float fDeg) {
	b2Body* ProjectileBody = CreateProjectile(fPositionX * PIXELS_METERS, fPositionY * PIXELS_METERS);

	if (fDeg == 0.0f) { // Up
		ProjectileBody->SetLinearVelocity(b2Vec2(0.0f, -20.0f));
	}
	if (fDeg == 90.0f) { // Right
		ProjectileBody->SetLinearVelocity(b2Vec2(20.0f, 0.0f));
	}
	if (fDeg == 180.0f) { // Down
		ProjectileBody->SetLinearVelocity(b2Vec2(0.0f, 20.0f));
	}
	if (fDeg == 270.0f) { // Left
		ProjectileBody->SetLinearVelocity(b2Vec2(-20.0f, 0.0f));
	}

	Projectile* NewProjectile = new Projectile("Bullet", ProjectileBody, "BULLET");

	m_Projectiles.push_back(NewProjectile);
}

void GameScene::SingleArrow(float fPositionX, float fPositionY, float fDeg) {
	b2Body* ProjectileBody = CreateProjectile(fPositionX * PIXELS_METERS, fPositionY * PIXELS_METERS);

	//fDeg = 180.0f * (b2_pi / 180.0f) + fDeg;

	// [TODO] Extremely weird math, plz help :(
	ProjectileBody->SetTransform(ProjectileBody->GetPosition(), 180.0f * (b2_pi / 180.0f) + fDeg);

	ProjectileBody->SetLinearVelocity(b2Vec2(20.0f * cosf(fDeg + 90.0f * (b2_pi / 180.0f)), 20.0f * sinf(fDeg + 90.0f * (b2_pi / 180.0f))));

	Projectile* NewProjectile = new Projectile("Arrow", ProjectileBody, "ARROW");

	m_Projectiles.push_back(NewProjectile);
}

void GameScene::UpdateScore() {

}

void GameScene::GameOver(sf::RenderWindow* window) {
	sf::RectangleShape r;
	r.setFillColor(sf::Color(0, 0, 0, 150));
	r.setSize(sf::Vector2f((float)WINDOW_W,(float)WINDOW_H));
	window->draw(r);
	sf::Text t;
	t.setString("GAME OVER");
	t.setCharacterSize(80);
	t.setStyle(sf::Text::Bold);
	t.setPosition(sf::Vector2f(150, 400));
	sf::Font f;
	f.loadFromFile("Resources/Font/VIDEOPHREAK.ttf");
	t.setFont(f);
	window->draw(t);
}

void GameScene::StageClear(sf::RenderWindow* window) {
	sf::RectangleShape r;
	r.setFillColor(sf::Color(0, 0, 0, 150));
	r.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));
	window->draw(r);
	sf::Text t;
	t.setString("STAGE CLEAR");
	t.setCharacterSize(80);
	t.setStyle(sf::Text::Bold);
	t.setPosition(sf::Vector2f(150, 400));
	sf::Font f;
	f.loadFromFile("Resources/Font/VIDEOPHREAK.ttf");
	t.setFont(f);
	window->draw(t);
}