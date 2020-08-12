#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// External Libraries
#include "SFML/Graphics.hpp"

// Local
#include "Singleton.h"
#include "MyObject.h"
#include "Player.h"

class GameScene {
private:
	//b2World* m_World = nullptr;

	std::vector<MyObject> m_SceneObjects;
	Player m_Player;
public:
	GameScene();
	~GameScene();

	void AddObject(MyObject NewObject);
	void Init();

	void Update(float fDeltaTime);
	void Render(sf::Window* MainWindow);
};