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
#include "MyContactListener.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "MyObject.h"
#include "Wall.h"
#include "Ground.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Projectile.h"
#include "PlayerGUI.h"
#include "Score.h"


class GameScene : public Singleton<GameScene> {
private:
	MyContactListener m_myContactListener;
	b2World* m_World;

	b2Body* CreateProjectile(float fX, float fY);
	b2Body* CreateSensor(float fX, float fY, float fSizeX, float fSizeY);
	b2Body* CreateBody(int iX, int iY, int iSizeX, int iSizeY, bool bStatic);
	b2Body* CreateWall(float iX, float iY, int iSizeX, int iSizeY, bool bStatic);

	std::vector<Wall*> m_Walls;
	std::vector<Ground> m_GroundTiles;


	Player m_Player;
	Boss m_Boss;
	std::vector<Enemy*> m_Enemies;
	std::vector<Projectile*> m_Projectiles;
	PlayerGUI* playerGUI;
	Score* score;

	// Scene loading functions
	void LoadTerrain(std::string strFilePath);
	void UpdateScore();
	void GameOver(sf::RenderWindow* MainWindow);
	void StageClear(sf::RenderWindow* MainWindow);
public:
	GameScene();
	~GameScene();

	void LoadFromFile(std::string strFilePath);

	float GetMouseAngleRadians(b2Vec2 fOrigin, b2Vec2 fTarget);
	void SingleShot(float fPositionX, float fPositionY, float fDeg);
	void SingleArrow(float fPositionX, float fPositionY, float fDeg);

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* MainWindow);
};