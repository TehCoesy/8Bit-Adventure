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

class GameOver: public State
{
private:
	sf::RectangleShape m_rec;
	sf::Text m_text;
	sf::Font m_font;
	std::vector<sf::Text> m_aButtons;
public:
	virtual void Init();

	virtual void HandleInput(sf::RenderWindow* window);
	virtual void Update(float dt);
	virtual void Render(sf::RenderWindow *window);

	virtual void Pause() { };
	virtual void Resume() { };


};