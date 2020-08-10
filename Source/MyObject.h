#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/b2_body.h"

class MyObject {
protected:
	sf::Sprite m_Sprite;

	b2Vec2 m_vPosition = b2Vec2(0.0f, 0.0f);
	b2Vec2 m_vVelocity = b2Vec2(0.0f, 0.0f);
public:
	MyObject();
	~MyObject();

	void CreateObject(sf::Texture Texture);

	void Update(float fDeltaTime);
	void Render();
};