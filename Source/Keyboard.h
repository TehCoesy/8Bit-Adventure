#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Window/Keyboard.hpp"

// Local
#include "Singleton.h"

class Keyboard : public Singleton<Keyboard> {
private:
	unsigned int uiKeysPressed;
	unsigned int uiKeysHold;
	unsigned int uiKeysReleased;

	static void SetBit(unsigned int* uiKeys, int iPosition);
	static void ClearBit(unsigned int* uiKeys, int iPosition);
	static bool GetBit(unsigned int* uiKeys, int iPosition);

	void GetInput();
public:
	enum Keys {
		UP, DOWN, LEFT, RIGHT, ATTACK
	};

	Keyboard();
	~Keyboard();

	bool GetKeyPressed(int iKey);
	bool GetKeyHold(int iKey);
	bool GetKeyReleased(int iKey);
};