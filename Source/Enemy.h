#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class Enemy : public MyObject {
public:
	Enemy();
	Enemy(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Enemy(const Enemy& cObject);
	~Enemy();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	void MoveDown(float fDeltaTime);
	void MoveUp(float fDeltaTime);
	void MoveLeft(float fDeltaTime);
	void MoveRight(float fDeltaTime);
};