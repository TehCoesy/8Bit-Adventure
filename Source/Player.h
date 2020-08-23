#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Player : public DynamicObject {
public:
	Player();
	Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Player(const Player& cObject);
	~Player();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};