// Precompiled Headers
#include "stdafx.h"

#include "GameScene.h"

GameScene::GameScene() {
	// Top-down 2D
	//if (!m_World) {
	//	b2Vec2 Gravity(0.0f, 0.0f);
	//	m_World = new b2World(Gravity);
	//}
}

GameScene::~GameScene() {
	//if (m_World) { delete(m_World); m_World = nullptr; }
}

void GameScene::AddObject(MyObject NewObject) {

}

void GameScene::Init() {
	m_PlayerTexture = RM->GetTexture("PLAYER_D_0");
	m_PlayerSprite.setTexture(*m_PlayerTexture.GetTexture());
	m_PlayerSprite.setScale(sf::Vector2f(2.0f, 2.0f));
}

void GameScene::Update(float fDeltaTime) {
	if (Keyboard::GetKey(Keyboard::UP)) {
		m_PlayerSprite.move(sf::Vector2f(0.0f, -1.0f));
	}
	if (Keyboard::GetKey(Keyboard::DOWN)) {
		m_PlayerSprite.move(sf::Vector2f(0.0f, 1.0f));
	}
	if (Keyboard::GetKey(Keyboard::LEFT)) {
		m_PlayerSprite.move(sf::Vector2f(-1.0f, 0.0f));
	}
	if (Keyboard::GetKey(Keyboard::RIGHT)) {
		m_PlayerSprite.move(sf::Vector2f(1.0f, 0.0f));
	}
}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	MainWindow->draw(m_PlayerSprite);
}