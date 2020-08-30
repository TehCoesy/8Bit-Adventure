#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"
#include "SoundManager.h"
#include "Attack.h"

class Player : public DynamicObject {
private:
	bool m_bIsAttacking = false;
	int m_iCount;
	int m_iSteps = 20;

	
public:
	Player();
	Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Player(const Player& cObject);
	~Player();

	Attack m_MeleeAttackDown, m_MeleeAttackUp, m_MeleeAttackLeft, m_MeleeAttackRight;

	void MeleeAttack();
	void SynchronizeSensor();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	void Move(float fDeltaTime, int iDirection);
	void Stop(float fDeltaTime, int iDirection);
};