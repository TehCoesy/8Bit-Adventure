#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"
#include "Attack.h"

class Player : public DynamicObject {
private:
	bool bIsAttacking;

	Attack m_MeleeAttack;
public:
	Player();
	Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Player(const Player& cObject);
	~Player();

	void MeleeAttack(b2Body* SensorBody);

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};