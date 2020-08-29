// Precompiled Headers
#include "stdafx.h"

#include "Keyboard.h"

Keyboard::Keyboard() {

}

Keyboard::~Keyboard() {

}

void Keyboard::GetInput() {
	// Movement control
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (!GetBit(&uiKeysHold, Keys::UP)) {
			SetBit(&uiKeysPressed, Keys::UP);
			ClearBit(&uiKeysReleased, Keys::UP);
		}
		SetBit(&uiKeysHold, Keys::UP);
	}
	else {
		if (GetBit(&uiKeysHold, Keys::UP)) {
			SetBit(&uiKeysReleased, Keys::UP);
			ClearBit(&uiKeysPressed, Keys::UP);
		}
		ClearBit(&uiKeysHold, Keys::UP);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (!GetBit(&uiKeysHold, Keys::DOWN)) {
			SetBit(&uiKeysPressed, Keys::DOWN);
			ClearBit(&uiKeysReleased, Keys::DOWN);
		}
		SetBit(&uiKeysHold, Keys::DOWN);
	}
	else {
		if (GetBit(&uiKeysHold, Keys::DOWN)) {
			SetBit(&uiKeysReleased, Keys::DOWN);
			ClearBit(&uiKeysPressed, Keys::DOWN);
		}
		ClearBit(&uiKeysHold, Keys::DOWN);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (!GetBit(&uiKeysHold, Keys::LEFT)) {
			SetBit(&uiKeysPressed, Keys::LEFT);
			ClearBit(&uiKeysReleased, Keys::LEFT);
		}
		SetBit(&uiKeysHold, Keys::LEFT);
	}
	else {
		if (GetBit(&uiKeysHold, Keys::LEFT)) {
			SetBit(&uiKeysReleased, Keys::LEFT);
			ClearBit(&uiKeysPressed, Keys::LEFT);
		}
		ClearBit(&uiKeysHold, Keys::LEFT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (!GetBit(&uiKeysHold, Keys::RIGHT)) {
			SetBit(&uiKeysPressed, Keys::RIGHT);
			ClearBit(&uiKeysReleased, Keys::RIGHT);
		}
		SetBit(&uiKeysHold, Keys::RIGHT);
	}
	else {
		if (GetBit(&uiKeysHold, Keys::RIGHT)) {
			SetBit(&uiKeysReleased, Keys::RIGHT);
			ClearBit(&uiKeysPressed, Keys::RIGHT);
		}
		ClearBit(&uiKeysHold, Keys::RIGHT);
	}

	// Actions
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (!GetBit(&uiKeysHold, Keys::ATTACK)) {
			SetBit(&uiKeysPressed, Keys::ATTACK);
			ClearBit(&uiKeysReleased, Keys::ATTACK);
		}
		SetBit(&uiKeysHold, Keys::ATTACK);
	}
	else {
		if (GetBit(&uiKeysHold, Keys::ATTACK)) {
			SetBit(&uiKeysReleased, Keys::ATTACK);
			ClearBit(&uiKeysPressed, Keys::ATTACK);
		}
		ClearBit(&uiKeysHold, Keys::ATTACK);
	}
}

bool Keyboard::GetKeyPressed(int iKey) {
	GetInput();
	bool bKeyPressed = GetBit(&uiKeysPressed, iKey);
	ClearBit(&uiKeysPressed, iKey);
	// Return only 1 KeysPressed event
	return bKeyPressed;
}

bool Keyboard::GetKeyHold(int iKey) {
	GetInput();
	return GetBit(&uiKeysHold, iKey);
}

bool Keyboard::GetKeyReleased(int iKey) {
	GetInput();
	bool bKeyReleased = GetBit(&uiKeysReleased, iKey);
	ClearBit(&uiKeysReleased, iKey);
	// Return only 1 KeysReleased event
	return bKeyReleased;
}

void Keyboard::SetBit(unsigned int* uiKeysPressed, int iPosition) {
	*uiKeysPressed |= 1 << iPosition;
}

void Keyboard::ClearBit(unsigned int* uiKeysPressed, int iPosition) {
	*uiKeysPressed &= ~(1 << iPosition);
}

bool Keyboard::GetBit(unsigned int* uiKeysPressed, int iPosition) {
	unsigned int bBit = *uiKeysPressed & (1 << iPosition);
	if (bBit == 0) {
		return false;
	}
	else {
		return true;
	}
}