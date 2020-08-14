#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"

// Local
#include "Singleton.h"
#include "SceneManager.h"
#include "ResourceManager.h" 
#include "GameScene.h"
#include "MainMenu.h"

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