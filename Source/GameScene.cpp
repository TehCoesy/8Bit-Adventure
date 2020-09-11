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
	state = 0;
	font.loadFromFile(FONT_VIDEOPHREAK);
	sf::Text t;
	t.setFont(font);
	t.setCharacterSize(20);
	t.setStyle(sf::Text::Bold);
	o_buttons.push_back(t);
	o_buttons.push_back(t);
	o_buttons.push_back(t);
	o_buttons[0].setString("Play Again");
	o_buttons[1].setString("Title Screen");
	o_buttons[2].setString("Quit Game");
	float margin = 30.0f;
	float o_row = 750.0f;
	float x = (float)WINDOW_W - 2*margin;
	for (int i = 0; i < 3; i++) {
		x -= o_buttons[i].getGlobalBounds().width;
	}
	x /= 2.0f;
	float pos = margin;
	for (int i = 0; i < 3; i++) {
		o_buttons[i].setPosition(pos, o_row);
		pos += o_buttons[i].getGlobalBounds().width+x;
	}
	p_state = 0;
}

GameScene::~GameScene() {
	if (m_World) { delete(m_World); }
	if (playerGUI) { delete (playerGUI); }
	if (score) { delete score; }
}

void GameScene::Init() {
	FILE* FileStream;
	
	FileStream = fopen(GAMESCENE_FILEPATH, "r");

	if (FileStream) {
		// Load terrain
		LoadTerrain(STAGE1_TERRAIN_FILEPATH);

		// Load objects
		b2Body* PlayerBody = CreateBody(5, 5, 1, 1, false);
		m_Player = new Player(0, "PLAYER", "PLAYER_IDLE_DOWN", PlayerBody, b2Vec2(TILE_SIZE, TILE_SIZE));

		//b2Body* EnemyBody1 = CreateBody(16, 8, 1, 1, false);
		b2Body* EnemyBody2 = CreateBody(8, 8, 1, 1, false);
		b2Body* EnemyBody3 = CreateBody(8, 16, 1, 1, false);
		Enemy* Skele1 = new Enemy(0, "SKELE", "SKELE", EnemyBody3, b2Vec2(TILE_SIZE, TILE_SIZE));
		m_Enemies.push_back(Skele1);
		Enemy* Skele2 = new Enemy(0, "SKELE", "SKELE", EnemyBody2, b2Vec2(TILE_SIZE, TILE_SIZE));
		m_Enemies.push_back(Skele2);

		fclose(FileStream);
	}

	// Others
	SoundManager::GetInstance()->PlayMusicByName("CELESTIAL");
	this->playerGUI = new PlayerGUI((this->m_Player));
	this->score = new Score((this->m_Player));
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

				b2Body* WallBody = CreateWall((float)iCorX, (float)iCorY, iHor, iVer, true);

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

				b2Body* WallBody = CreateWall((float)iCorX, (float)iCorY, 0, 0, true);

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

b2Body* GameScene::CreateBodyWithSprite(int iTileX, int iTileY, sf::Sprite graSprite) {
	return nullptr;
}

void GameScene::Update(float fDeltaTime) {
	float fPlayerPosX = m_Player->GetPhysicsBody()->GetWorldCenter().x * PIXELS_METERS;
	float fPlayerPosY = m_Player->GetPhysicsBody()->GetWorldCenter().y * PIXELS_METERS;
	MainCamera->SetCameraPosition(fPlayerPosX,fPlayerPosY);
	if (state) return;
	// Update Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) state = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) state = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) state = 3;
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
	
	if (Mouse::GetInstance()->IsPressed()) {
		b2Vec2 fOrigin = MainCamera->GetCameraCenter();
		float fAngle = GetMouseAngleRadians(fOrigin, b2Vec2(Mouse::GetInstance()->GetPosition().x, Mouse::GetInstance()->GetPosition().y));
		//printf("%f\n", )
		SingleArrow(m_Player->GetPhysicsBody()->GetWorldCenter().x + 1.0f, m_Player->GetPhysicsBody()->GetWorldCenter().y + 1.0f, fAngle);
		SM->PlayEffectByName("PLAYER_ATTACK");
	}

	for (unsigned int i = 0; i < m_Enemies.size(); i++) {
		Normal_Enemy::GetInstance()->Interaction(m_Enemies.at(i), fPlayerPosX, fPlayerPosY, fDeltaTime);
		m_Enemies.at(i)->Update(fDeltaTime);
	}

	for (unsigned int i = 0; i < m_Projectiles.size(); i++) {
		m_Projectiles.at(i)->Update(fDeltaTime);
	}
	
	m_Player->Update(fDeltaTime);

	m_World->Step(fDeltaTime, 4, 2);

	Clean();
}

void GameScene::HandleInput(sf::RenderWindow* window)
{

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
	if (state == 1) {
		Pause(MainWindow);
	}
	else if (state == 2) {
		GameOver(MainWindow);
	}
	else if (state == 3) {
		StageClear(MainWindow);
	}
	//GameOver(MainWindow);
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
	b2Body* ProjectileBody = CreateProjectile(fPositionX * PIXELS_METERS, fPositionY * PIXELS_METERS, 10.0f, 10.0f);

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
	b2Body* ProjectileBody = CreateProjectile(fPositionX * PIXELS_METERS, fPositionY * PIXELS_METERS, 10.0f, 10.0f);

	//fDeg = 180.0f * (b2_pi / 180.0f) + fDeg;

	// [TODO] Extremely weird math, plz help :(
	ProjectileBody->SetTransform(ProjectileBody->GetPosition(), 180.0f * (b2_pi / 180.0f) + fDeg);

	ProjectileBody->SetLinearVelocity(b2Vec2(20.0f * cosf(fDeg + 90.0f * (b2_pi / 180.0f)), 20.0f * sinf(fDeg + 90.0f * (b2_pi / 180.0f))));

	Projectile* NewProjectile = new Projectile("Arrow", ProjectileBody, "ARROW");

	m_Projectiles.push_back(NewProjectile);
}

void GameScene::UpdateScore() {

}

bool GameScene::isTextClicked(sf::RenderWindow* window, sf::Text text) {
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	if (rect.contains(sf::Mouse::getPosition(*window)))
		return true;

	return false;
}

void GameScene::GameOver(sf::RenderWindow* window) {
	sf::RectangleShape r;
	r.setFillColor(sf::Color(0, 0, 0, 150));
	r.setSize(sf::Vector2f((float)WINDOW_W,(float)WINDOW_H));
	window->draw(r);
	sf::Text t;
	t.setFont(font);
	t.setString("GAME OVER");
	t.setCharacterSize(80);
	t.setStyle(sf::Text::Bold);
	//t.setPosition(sf::Vector2f(150, 400));
	t.setPosition(sf::Vector2f((float)((WINDOW_W - t.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - t.getGlobalBounds().height) / 2.0f)));
	window->draw(t);
	for (auto x : o_buttons) {
		window->draw(x);
	}
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::MouseMoved:
			if (isTextClicked(window, o_buttons[0]))
				o_buttons[0].setFillColor(sf::Color::Yellow);
			else
				o_buttons[0].setFillColor(sf::Color::White);
			if (isTextClicked(window, o_buttons[1]))
				o_buttons[1].setFillColor(sf::Color::Yellow);
			else
				o_buttons[1].setFillColor(sf::Color::White);
			if (isTextClicked(window, o_buttons[2]))
				o_buttons[2].setFillColor(sf::Color::Yellow);
			else
				o_buttons[2].setFillColor(sf::Color::White);
			break;
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (isTextClicked(window, o_buttons[0])) {
			state = 0;
		}
		if (isTextClicked(window, o_buttons[1])) {
			state = 0;
			StateMachine->AddState(StateRef(new MainMenu()));
		}
		if (isTextClicked(window, o_buttons[2])) {
			window->close();
		}
	}
}

void GameScene::StageClear(sf::RenderWindow* window) {
	sf::RectangleShape r;
	r.setFillColor(sf::Color(0, 0, 0, 150));
	r.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));
	window->draw(r);
	sf::Text t;
	t.setFont(font);
	t.setString("STAGE CLEAR");
	t.setCharacterSize(80);
	t.setStyle(sf::Text::Bold);
	t.setPosition(sf::Vector2f((float)((WINDOW_W - t.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - t.getGlobalBounds().height) / 2.0f)));
	window->draw(t);
	t.setString("Click to continue...");
	t.setCharacterSize(20);
	t.setPosition(sf::Vector2f((float)((WINDOW_W - t.getGlobalBounds().width) / 2.0f), 750.0f));
	window->draw(t);
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && w_state == 0) {
		w_state = 1;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && w_state == 1) {
		w_state = 2;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && w_state == 2) {
		w_state = 0;
		state = 0;
		StateMachine->AddState(StateRef(new MainMenu()));
	}
}

void GameScene::Pause(sf::RenderWindow* window) {
	sf::RectangleShape r;
	r.setFillColor(sf::Color(0, 0, 0, 150));
	r.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));
	window->draw(r);
	sf::Text t;
	t.setFont(font);
	t.setString("PAUSED");
	t.setCharacterSize(80);
	t.setStyle(sf::Text::Bold);
	t.setPosition(sf::Vector2f((float)((WINDOW_W - t.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - t.getGlobalBounds().height) / 2.0f)));
	window->draw(t);

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && p_state == 0) {
		p_state = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && p_state == 1) {
		p_state = 2;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && p_state == 2) {
		p_state = 0;
		state = 0;
	}
}