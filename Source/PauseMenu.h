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
#include "Player.h"

class PauseMenu : public State
{
private:
	sf::RectangleShape m_rec;
	sf::Text m_text;
	sf::Font m_font;
	std::vector<sf::Text> m_aButtons;
	std::vector<sf::Text> m_Objective;
	int p_state;
	bool resume, toTitle;
	int elap_time;
	Player* player;
	//PlayerGUI* playerGUI;
	bool isTextClicked(sf::RenderWindow* window, sf::Text text);
public:
	PauseMenu(int time,Player* player);
	virtual void Init();

	virtual void HandleInput(sf::RenderWindow* window);
	virtual void Update(float dt);
	virtual void Render(sf::RenderWindow *window);

	virtual void Pause() { };
	virtual void Resume() { };

};