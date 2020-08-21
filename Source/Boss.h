#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class Boss : public MyObject {
public:
	Boss();
	Boss(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Boss(const Boss& cObject);
	~Boss();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	void MoveDown(float fDeltaTime);
	void MoveUp(float fDeltaTime);
	void MoveLeft(float fDeltaTime);
	void MoveRight(float fDeltaTime);
};