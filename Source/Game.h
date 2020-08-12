#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Box2D/b2_world.h"

// Local
#include "Singleton.h"
#include "SceneManager.h"
#include "ResourceManager.h" 
#include "GameScene.h"
#include "MainMenu.h"

#define SM SceneManager::GetInstance()
#define RM ResourceManager::GetInstance()

class Game : public Singleton<Game> {
private:
	sf::RenderWindow m_MainWindow;
	sf::Clock m_Clock;

	GameScene m_GameScene;
	MainMenu m_MainMenu;

	void Update(float fDeltaTime);
	void Render();
public:
	Game();
	~Game();

	void Init();
	void RunMainLoop();
};