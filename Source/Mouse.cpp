// Precompiled Headers
#include "stdafx.h"

#include "Mouse.h"

Mouse::Mouse() {
}

Mouse::~Mouse() {
}

bool Mouse::IsHeld() {
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

bool Mouse::IsPressed() {
	if (IsHeld() && m_CurrentState == RELEASED) {
		m_CurrentState = EVENT_CALLED;
		return true;
	}
	else if (IsHeld() && m_CurrentState == EVENT_CALLED) {
		return false;
	}
	else if (!IsHeld()) {
		m_CurrentState = RELEASED;
		return false;
	}
	else {
		return false;
	}
}

sf::Vector2i Mouse::GetPosition() {
	return sf::Mouse::getPosition(*Game::GetInstance()->GetMainWindow());
}