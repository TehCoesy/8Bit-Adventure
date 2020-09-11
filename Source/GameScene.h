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
#include "Normal_Enemy.h"
#include "PlayerGUI.h"
#include "Score.h"
#include "State.h"


class GameScene : public State {
private:
	// PhysicsWorld
	MyContactListener m_myContactListener;
	b2World* m_World;

	// PhysicsBody creation
	b2Body* CreateProjectile(float fX, float fY, float fSizeX, float fSizeY);
	b2Body* CreateSensor(float fX, float fY, float fSizeX, float fSizeY);
	b2Body* CreateBody(int iX, int iY, int iSizeX, int iSizeY, bool bStatic);
	b2Body* CreateWall(float iX, float iY, int iSizeX, int iSizeY, bool bStatic);
	b2Body* CreateBodyWithSprite(int iTileX, int iTileY, sf::Sprite graSprite);

	// GameObjects
	std::vector<Ground*> m_GroundTiles;
	std::vector<Wall*> m_Walls;

	Player* m_Player;

	std::vector<Projectile*> m_Projectiles;
	Boss* m_Boss;
	std::vector<Enemy*> m_Enemies;
	int state; //0:Playing, 1:Pause, 2: Gameover, 3: StageClear
	sf::Font font;
	std::vector<sf::Text> p_buttons;
	std::vector<sf::Text> o_buttons;
	int p_state;
	std::vector<sf::Text> w_buttons;
	int w_state;
	// UI
	PlayerGUI* playerGUI;
	Score* score;
	// Scene loading functions
	void LoadTerrain(std::string strFilePath);
	void UpdateScore();
	void GameOver(sf::RenderWindow* MainWindow);
	void StageClear(sf::RenderWindow* MainWindow);
	void Pause(sf::RenderWindow* MainWindow);
	bool isTextClicked(sf::RenderWindow* window, sf::Text text);

	// Clean-up functions
	std::vector<MyObject*> m_objectsScheduledForRemoval;
	void Clean();
public:
	GameScene();
	~GameScene();
	
	// Scene loading functions
	
	void Init();
	void HandleInput(sf::RenderWindow* window);
	// Shooting projectiles
	float GetMouseAngleRadians(b2Vec2 fOrigin, b2Vec2 fTarget);

	void SingleShot(float fPositionX, float fPositionY, float fDeg);
	void SingleArrow(float fPositionX, float fPositionY, float fDeg);

	// Core functions
	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* MainWindow);
};