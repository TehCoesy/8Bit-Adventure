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
#include "Normal_Enemy.h"
#include "PauseMenu.h"
#include "GameOver.h"
#include "StageClear.h"
#include "SettingArg.h"

class GameScene : public State {
private:
	// PhysicsWorld
	MyContactListener m_myContactListener;
	b2World* m_World;

	// PhysicsBody creation
	b2Body* CreateProjectile(float fX, float fY, float fSizeX, float fSizeY);
	b2Body* CreateSensor(float fX, float fY, float fSizeX, float fSizeY);
	b2Body* CreateBody(int iX, int iY, int iSizeX, int iSizeY, bool bStatic);
	b2Body* CreateWall(float iX, float iY, int iSizeX, int iSizeY, bool bStatic, bool bCollision);
	b2Body* CreateBodyWithSprite(int iTileX, int iTileY, sf::Sprite graSprite);

	// GameObjects
	std::vector<Ground*> m_GroundTiles;
	std::vector<Wall*> m_Walls;

	Player* m_Player;

	std::vector<Projectile*> m_Projectiles;
	Boss* m_Boss;
	std::vector<Enemy*> m_Enemies;
	static int infCount;
	sf::Font font;
	bool fix;
	int mode;
	int dif;
	int frameCount;

	// UI
	PlayerGUI* playerGUI;
	Score* score;

	//check variables
	
	bool isWin();

	// Scene loading functions
	void LoadTerrain(std::string strFilePath);
	void LoadObject(std::string strFilePath);
	void LoadPlayer(std::string strFilePath);


	// Clean-up functions
	std::vector<MyObject*> m_objectsScheduledForRemoval;
	void Clean();
public:
	GameScene();
	GameScene(int dif, int mode);
	~GameScene();
	
	// Scene loading functions
	
	void Pause();
	void Resume();
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