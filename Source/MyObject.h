#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"

class MyObject {
protected:
	sf::Sprite m_Sprite;
public:
	MyObject();
	~MyObject();

	void CreateObject(sf::Texture Texture);

	void Update(float fDeltaTime);
	void Render();
};