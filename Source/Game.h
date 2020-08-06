#pragma once

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

// Local
#include "Singleton.h"

// Macros
#define WINDOW_W 500
#define WINDOW_H 500
#define WINDOW_TITLE "Hello!"
#define FRAMERATE 60.0f

class Game : public Singleton<Game> {
private:
	sf::RenderWindow m_MainWindow;
	sf::Clock m_Clock;

	sf::CircleShape m_TestShape;

	void Update(float fDeltaTime);
	void Render();
public:
	void Init();
	void RunMainLoop();
};