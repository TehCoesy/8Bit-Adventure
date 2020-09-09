#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Window/Mouse.hpp"
#include "SFML/System/Vector2.hpp"

// Local
#include "Singleton.h"
#include "Game.h"

class Mouse : public Singleton<Mouse> {
private:
	enum States {
		RELEASED, PRESSED, EVENT_CALLED
	};

	int m_CurrentState = 0;
public:
	Mouse();
	~Mouse();

	bool IsPressed();
	bool IsHeld();
	sf::Vector2i GetPosition();
};