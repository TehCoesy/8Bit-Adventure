#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Window/Keyboard.hpp"

class Keyboard {
private:
	static void SetBit(unsigned int* uiKeys, int iPosition);
	static void ClearBit(unsigned int* uiKeys, int iPosition);
	static bool GetBit(unsigned int* uiKeys, int iPosition);
public:
	enum Keys {
		UP, DOWN, LEFT, RIGHT, ATTACK
	};

	Keyboard();
	~Keyboard();
	
	static unsigned int GetInput();
	static bool GetKey(int iKey);
};