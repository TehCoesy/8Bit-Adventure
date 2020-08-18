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
	// Experimental Player Object
	m_PlayerTexture = RM->GetTexture("PLAYER_D_0");
	m_PlayerSprite.setTexture(*m_PlayerTexture.GetTexture());
	m_PlayerSprite.setScale(sf::Vector2f(2.0f, 2.0f));

	float PositionX = 0.0f, PositionY = 0.0f; // Pixel Coordinate

	// BodyDef
	b2BodyDef m_BodyDef;
	m_BodyDef.position = b2Vec2(PositionX / PIXELS_METERS, PositionY / PIXELS_METERS);
	m_BodyDef.type = b2_dynamicBody;

	m_PlayerPhysicsBody = m_World->CreateBody(&m_BodyDef);

	// BoxShape
	b2PolygonShape m_BoxShape;
	m_BoxShape.SetAsBox(64.0f / 2, 32.0f / 2); // Takes 1/2 Width and 1/2 Height

	// FixtureDef
	b2FixtureDef m_Fixture;
	m_Fixture.density = 0.0f;
	m_Fixture.shape = &m_BoxShape;

	// Finalize Player's Physic Body
	m_PlayerPhysicsBody->CreateFixture(&m_Fixture);

	// Synchronize RectangleBox and Sprite to PhysicsBody
	m_PhysicsBodyBox.setOrigin(0.0f, 0.0f);
	m_PhysicsBodyBox.setSize(sf::Vector2f(64.0f, 32.0f));
	m_PhysicsBodyBox.setPosition(m_PlayerPhysicsBody->GetPosition().x * PIXELS_METERS, m_PlayerPhysicsBody->GetPosition().y * PIXELS_METERS + 32.0f);
	m_PhysicsBodyBox.setRotation(m_PlayerPhysicsBody->GetAngle() * 180 / b2_pi);
	m_PhysicsBodyBox.setFillColor(sf::Color::Transparent);
	m_PhysicsBodyBox.setOutlineColor(sf::Color::Blue);
	m_PhysicsBodyBox.setOutlineThickness(2.0f);

	m_PlayerSprite.setPosition(m_PlayerPhysicsBody->GetPosition().x * PIXELS_METERS, m_PlayerPhysicsBody->GetPosition().y * PIXELS_METERS);

	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		// PlaceHolder Scene, for testing;

		// Close FileStream
		fclose(FileStream);
	}
}

void GameScene::Update(float fDeltaTime) {
	// Update Input
	float VelX = 0.0f, VelY = 0.0f;

	if (Keyboard::GetKey(Keyboard::UP)) {
		VelY = -2.0f;
	}
	if (Keyboard::GetKey(Keyboard::DOWN)) {
		VelY = 2.0f;
	}
	if (Keyboard::GetKey(Keyboard::LEFT)) {
		VelX = -2.0f;
	}
	if (Keyboard::GetKey(Keyboard::RIGHT)) {
		VelX = 2.0f;
	}

	m_PlayerPhysicsBody->SetLinearVelocity(b2Vec2(VelX, VelY));

	// Update Sprites
	m_PhysicsBodyBox.setPosition(m_PlayerPhysicsBody->GetPosition().x * PIXELS_METERS, m_PlayerPhysicsBody->GetPosition().y * PIXELS_METERS + 32.0f);
	m_PlayerSprite.setPosition(m_PlayerPhysicsBody->GetPosition().x * PIXELS_METERS, m_PlayerPhysicsBody->GetPosition().y * PIXELS_METERS);

	m_World->Step(fDeltaTime, 4, 2);
}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	MainWindow->draw(m_PlayerSprite);
	MainWindow->draw(m_PhysicsBodyBox);
}