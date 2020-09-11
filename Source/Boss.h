#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Boss : public DynamicObject {
private:
	Boss(Boss const&) = delete;
	Boss& operator=(Boss const&) = delete;
public:
	Boss();
	Boss(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	~Boss();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};