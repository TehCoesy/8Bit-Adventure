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
	m_PlayerTexture.loadFromFile("./Resources/Textures/PLAYER_D_0.png");
	m_PlayerSprite.setTexture(m_PlayerTexture);
}

void GameScene::Update(float fDeltaTime) {

}

void GameScene::Render(sf::RenderWindow* MainWindow) {
	MainWindow->draw(m_PlayerSprite);
}