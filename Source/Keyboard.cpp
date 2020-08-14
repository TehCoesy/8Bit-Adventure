// Precompiled Headers
#include "stdafx.h"

#include "Keyboard.h"

Keyboard::Keyboard() {

}

Keyboard::~Keyboard() {

}

unsigned int Keyboard::GetInput() {
	unsigned int uiKeysPressed = 0;

	// Movement control
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		SetBit(&uiKeysPressed, Keys::UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		SetBit(&uiKeysPressed, Keys::DOWN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		SetBit(&uiKeysPressed, Keys::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		SetBit(&uiKeysPressed, Keys::RIGHT);
	}

	return uiKeysPressed;
}

bool Keyboard::GetKey(int iKey) {
	unsigned int uiKeysPressed = GetInput();

	return GetBit(&uiKeysPressed, iKey);
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