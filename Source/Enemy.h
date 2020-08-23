#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Enemy : public DynamicObject {
public:
	Enemy();
	Enemy(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Enemy(const Enemy& cObject);
	~Enemy();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};