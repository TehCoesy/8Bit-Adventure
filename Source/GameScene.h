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

#include "MyObject.h"
#include "Wall.h"
#include "Ground.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

class GameScene {
private:
	b2World* m_World;

	std::vector<Wall> m_Walls;
	std::vector<Ground> m_GroundTiles;

	Player m_Player;
	Boss m_Boss;
	std::vector<Enemy> m_Enemies;

	// Scene loading functions
	void LoadTerrain(std::string strFilePath);
public:
	GameScene();
	~GameScene();

	void LoadFromFile(std::string strFilePath);

	b2Body* CreateBody(int iX, int iY, int iSizeX, int iSizeY, bool bStatic);

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* MainWindow);
};