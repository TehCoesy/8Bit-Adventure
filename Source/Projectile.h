#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

class Projectile {
private:
	sf::Sprite m_Sprite;
	b2Body* m_PhysicsBody;
public:
	Projectile();
	~Projectile();
};