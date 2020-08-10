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

// Macros
#define WINDOW_W 500
#define WINDOW_H 500
#define WINDOW_TITLE "8Bit-Adventure"
#define FRAMERATE 60.0f

#define SM SceneManager::GetInstance()
#define RM ResourceManager::GetInstance()

class Game : public Singleton<Game> {
private:
	sf::RenderWindow m_MainWindow;
	sf::Clock m_Clock;

	GameScene m_GameScene;

	void Update(float fDeltaTime);
	void Render();
public:
	Game();
	~Game();

	void Init();
	void RunMainLoop();
};