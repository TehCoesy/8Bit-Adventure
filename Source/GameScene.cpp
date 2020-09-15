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

	font.loadFromFile(FONT_VIDEOPHREAK);
	sf::Text t;
	t.setFont(font);
	t.setCharacterSize(20);
	t.setStyle(sf::Text::Bold);
	fix = false;
	

}

GameScene::~GameScene() {
	if (m_World) { delete(m_World); }
	if (playerGUI) { delete (playerGUI); }
	if (score) { delete score; }
}

void GameScene::Init() {
	//Load Player
	LoadPlayer(STAGE1_PLAYER_FILEPATH);

	// Load objects
	LoadObject(STAGE1_OBJECTS_FILEPATH);
	
	// Load terrain
	LoadTerrain(STAGE1_TERRAIN_FILEPATH);

	// Others
	SM->PlayMusicByName("CELESTIAL");
	this->playerGUI = new PlayerGUI((this->m_Player));
	this->score = new Score((this->m_Player));
}

void GameScene::LoadObject(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;
		int iNumEnemyType;
		fscanf(FileStream, "#ENEMIES %d\n", &iNumEnemyType);
		for (int i = 0; i < iNumEnemyType; i++)
		{
			int iHealth, iScores, iDamage, iAmount;
			char strName[100];
			iVal = fscanf(FileStream, "NAME: %s HEALTH: %d SCORES: %d DAMAGE: %d AMOUNT: %d\n", strName, &iHealth, &iScores, &iDamage, &iAmount);
	
			for (int j = 0; j < iAmount; j++)
			{
				int iID, iPos_X, iPos_Y;
				fscanf(FileStream, "ID: %d, POS_X: %d, POS_Y: %d\n", &iID, &iPos_X, &iPos_Y);
				//skeleton
				if (strcmp(strName, "SKELETON") == 0)
				{
					b2Body* EnemyBody = CreateBody(iPos_X, iPos_Y, 1, 1, false);
					Enemy* Skele = new Enemy(iID, "SKELE", "SKELE", EnemyBody, b2Vec2(TILE_SIZE, TILE_SIZE), iHealth, iScores, iDamage,m_Player);
					m_Enemies.push_back(Skele);

				}
			}
		}
		

		fclose(FileStream);
	}
}
void GameScene::LoadPlayer(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;

		int iHealth, iScores, iDamage, iPosX, iPosY;
		char strName[100];
		iVal = fscanf(FileStream, "NAME: %s HEALTH: %d SCORES: %d DAMAGE: %d POS_X: %d POS_Y: %d\n", strName, &iHealth, &iScores, &iDamage, &iPosX, &iPosY);

		b2Body* PlayerBody = CreateBody(iPosX, iPosY, 1, 1, false);
		m_Player = new Player(0, "PLAYER", "PLAYER_IDLE_DOWN", PlayerBody, b2Vec2(TILE_SIZE, TILE_SIZE), iHealth, iScores, iDamage);

		fclose(FileStream);
	}
}

void GameScene::LoadTerrain(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;

		// Map
		int iWidth, iHeight;
		iVal = fscanf(FileStream, "#SIZE WIDTH %d HEIGHT %d\n", &iWidth, &iHeight);

		// Ground tiles
		int iVer, iHor;
		char cName[100];
		iVal = fscanf(FileStream, "#GROUND\n");
		iVal = fscanf(FileStream, "NAME: %s VERTICAL: %d HORIZONTAL: %d\n", cName, &iVer, &iHor);
		for (int i = 0; i < iVer; i++)
		{
			for (int j = 0; j < iHor; j++)
			{
				Ground* NewGroundTile = new Ground(cName, j, i);
				m_GroundTiles.push_back(NewGroundTile);
			}
		}

		// Walls
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

				b2Body* WallBody = CreateWall((float)iCorX, (float)iCorY, iHor, iVer, true, true);

				Wall *NewWall = new Wall(iID, "WALL", cName, WallBody, iHor, iVer, iCorX, iCorY);

				m_Walls.push_back(NewWall);
			}
		}

		// Decors
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

				b2Body* WallBody = CreateWall((float)iCorX, (float)iCorY, 0, 0, true, false);

				Wall *NewWall = new Wall(iID, "DECOR", cName, WallBody, iHor, iVer, iCorX, iCorY);

				m_Walls.push_back(NewWall);
			}
		}

		fclose(FileStream);
	}
}

b2Body* GameScene::CreateProjectile(float fPositionX, float fPositionY, float fSizeX, float fSizeY) {
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

b2Body* GameScene::CreateBody(int iTileX, int iTileY, int iTileSizeX, int iTileSizeY, bool bStatic)
{
	float fPositionX = TILE_SIZE * iTileX, fPositionY = TILE_SIZE * iTileY;
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
	BodyShape.SetAsBox(((TILE_SIZE * iTileSizeX) / 2) / PIXELS_METERS, ((TILE_SIZE * iTileSizeY) / 2) / PIXELS_METERS); // Takes 1/2 Width and 1/2 Height

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &BodyShape;

	PhysicsBody->CreateFixture(&FixtureDef);

	return PhysicsBody;
}

b2Body* GameScene::CreateWall(float iX, float iY, int iSizeX, int iSizeY, bool bStatic, bool bCollision)
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

	if (!bCollision) {
		FixtureDef.isSensor = true;
	}

	PhysicsBody->CreateFixture(&FixtureDef);

	return PhysicsBody;
}

b2Body* GameScene::CreateBodyWithSprite(int iTileX, int iTileY, sf::Sprite graSprite) {
	return nullptr;
}

void GameScene::Pause()
{
	SM->SetVolume(20.f);
}

void GameScene::Resume()
{
	SM->SetVolume(100.f);
}

void GameScene::Update(float fDeltaTime) {
	float fPlayerPosX = m_Player->GetPhysicsBody()->GetWorldCenter().x * PIXELS_METERS;
	float fPlayerPosY = m_Player->GetPhysicsBody()->GetWorldCenter().y * PIXELS_METERS;
	MainCamera->SetCameraPosition(fPlayerPosX,fPlayerPosY);

	// Update Input
	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::DOWN)) {
		m_Player->Move(fDeltaTime, 0);
	}
	else {
		m_Player->Stop(fDeltaTime, 0);
	}

	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::UP)) {
		m_Player->Move(fDeltaTime, 1);
	}
	else {
		m_Player->Stop(fDeltaTime, 1);
	}

	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::LEFT)) {
		m_Player->Move(fDeltaTime, 2);
	}
	else {
		m_Player->Stop(fDeltaTime, 2);
	}

	if (Keyboard::GetInstance()->GetKeyHold(Keyboard::RIGHT)) {
		m_Player->Move(fDeltaTime, 3);
	}
	else {
		m_Player->Stop(fDeltaTime, 3);
	}
	


	for (unsigned int i = 0; i < m_Enemies.size(); i++) {
		Normal_Enemy::GetInstance()->Interaction(m_Enemies.at(i), fPlayerPosX, fPlayerPosY, fDeltaTime);
		m_Enemies.at(i)->Update(fDeltaTime);
	}

	for (unsigned int i = 0; i < m_Projectiles.size(); i++) {
		m_Projectiles.at(i)->Update(fDeltaTime);
	}
	
	m_Player->Update(fDeltaTime);
	playerGUI->update(fDeltaTime);

	m_World->Step(fDeltaTime, 4, 2);

	//update score
	score->Update();

	//change gameover state
	if (m_Player->isDead())
	{
		StateMachine->AddState(StateRef(new GameOver));
	}

	//change stageclear state
	if (isWin())
	{
		StateMachine->AddState(StateRef(new StageClear()));
	}

	Clean();

}
bool GameScene::isWin()
{
	for (int i = 0; i < m_Enemies.size(); i++)
	{
		if (!m_Enemies.at(i)->isDead())
		{
			return false;
		}
	}
	return true;
}

void GameScene::HandleInput(sf::RenderWindow* window)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !fix) fix = true;
	if (Mouse::GetInstance()->IsPressed() && fix) {
		b2Vec2 fOrigin = MainCamera->GetCameraCenter();
		float fAngle = GetMouseAngleRadians(fOrigin, b2Vec2(Mouse::GetInstance()->GetPosition().x, Mouse::GetInstance()->GetPosition().y));
		//printf("%f\n", )
		SingleArrow(m_Player->GetPhysicsBody()->GetWorldCenter().x, m_Player->GetPhysicsBody()->GetWorldCenter().y, fAngle);
		SM->PlayEffectByName("PLAYER_ATTACK");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		StateMachine->AddState(StateRef(new PauseMenu()), false);
	}
}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	for (unsigned int i = 0; i < m_GroundTiles.size(); i++) {
		m_GroundTiles.at(i)->Render(MainWindow);
	}
	
	for (unsigned int i = 0; i < m_Walls.size(); i++) {
		m_Walls.at(i)->Render(MainWindow);
	}

	for (unsigned int i = 0; i < m_Enemies.size(); i++) {
		m_Enemies.at(i)->Render(MainWindow);
}

	for (unsigned int i = 0; i < m_Projectiles.size(); i++) {
		m_Projectiles.at(i)->Render(MainWindow);
	}
	m_Player->Render(MainWindow);
	playerGUI->render(MainWindow);
	score->Render(MainWindow);
}

void GameScene::Clean() {
	for (unsigned int i = 0; i < m_Projectiles.size(); i++) {
		if (m_Projectiles.at(i)->GetObjectState() == ObjectState::DESTROYED) {
			Projectile* removedObject = m_Projectiles.at(i);
			m_Projectiles.erase(m_Projectiles.begin() + i);
			delete removedObject;
		}
	}

	for (unsigned int i = 0; i < m_Enemies.size(); i++) {
		if (m_Enemies.at(i)->GetObjectState() == ObjectState::DESTROYED) {
			Enemy* removedObject = m_Enemies.at(i);
			m_Enemies.erase(m_Enemies.begin() + i);
			delete removedObject;
		}
	}
}

float GameScene::GetMouseAngleRadians(b2Vec2 fOrigin, b2Vec2 fTarget) {
	b2Vec2 toTarget = fTarget - fOrigin;
	float fAngle = atan2f(-toTarget.x, toTarget.y);
	return fAngle;
}

void GameScene::SingleShot(float fPositionX, float fPositionY, float fDeg) {
	b2Body* ProjectileBody = CreateProjectile(fPositionX * PIXELS_METERS, fPositionY * PIXELS_METERS, 10.0f, 20.0f);

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

	Projectile* NewProjectile = new Projectile("Bullet", ProjectileBody, "BULLET", 0, ObjectType::PLAYER, b2Vec2(10.0f, 20.0f));

	m_Projectiles.push_back(NewProjectile);
}

void GameScene::SingleArrow(float fPositionX, float fPositionY, float fDeg) {
	b2Body* ProjectileBody = CreateProjectile(fPositionX * PIXELS_METERS, fPositionY * PIXELS_METERS, 15.0f, 30.0f);

	//fDeg = 180.0f * (b2_pi / 180.0f) + fDeg;

	// [TODO] Extremely weird math, plz help :(
	ProjectileBody->SetTransform(ProjectileBody->GetPosition(), 180.0f * (b2_pi / 180.0f) + fDeg);

	ProjectileBody->SetLinearVelocity(b2Vec2(20.0f * cosf(fDeg + 90.0f * (b2_pi / 180.0f)), 20.0f * sinf(fDeg + 90.0f * (b2_pi / 180.0f))));

	Projectile* NewProjectile = new Projectile("Arrow", ProjectileBody, "ARROW", 0, ObjectType::PLAYER, b2Vec2(15.0f, 30.0f));

	NewProjectile->SetDamage(m_Player->GetDamage());
	m_Projectiles.push_back(NewProjectile);
}




