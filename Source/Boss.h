#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Boss : public DynamicObject {
public:
	Boss();
	Boss(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Boss(const Boss& cObject);
	~Boss();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};