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

	sf::Sprite m_PlayerSprite;
	MyTexture m_PlayerTexture;

	std::vector<MyObject> m_SceneObjects;
	Player m_Player;
public:
	GameScene();
	~GameScene();

	void AddObject(MyObject NewObject);
	void Init();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* MainWindow);
};