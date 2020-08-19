#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

// Local
#include "Singleton.h"
#include "ResourceManager.h"
#include "Keyboard.h"
#include "MyTexture.h"
#include "MyObject.h"
#include "Player.h"

class GameScene {
private:
	b2World* m_World;

	

	sf::RectangleShape m_PhysicsBodyBox, m_SpriteBox;
	b2Body* m_PlayerPhysicsBody;
	Player m_Player;

	std::vector<MyObject> m_SceneObjects;
public:
	GameScene();
	~GameScene();

	void LoadPlayer(std::string strFilePath);
	void LoadFromFile(std::string strFile);

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* MainWindow);
};