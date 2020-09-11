#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"

// Local
#include "Singleton.h"
#include "ResourceManager.h" 
#include "SoundManager.h"
#include "GameScene.h"
#include "MainMenu.h"
#include "StateManager.h"


class Game : public Singleton<Game> {
private:
	sf::RenderWindow m_MainWindow;
	sf::Clock m_Clock;

	void Update(float fDeltaTime);
	void Render();
public:
	Game();
	~Game();

	sf::RenderWindow* GetMainWindow();

	void Init();
	void RunMainLoop();
};