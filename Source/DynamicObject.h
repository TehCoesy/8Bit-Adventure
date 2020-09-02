#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

class DynamicObject : public SpriteObject {
protected:
	bool m_bMovingDown, m_bMovingUp, m_bMovingLeft, m_bMovingRight;
	int m_iDirection = 0; // 0 = Down; 1 = Up; 2 = Left; 3 = Right

	float m_fMaxVelocity = 5.0f;

	bool m_bCanMove = true;
	bool m_bIsDead = false;
public:
	DynamicObject();
	~DynamicObject();

	enum Direction {
		DOWN = 0, UP = 1, LEFT = 2, RIGHT = 3
	};

	enum State {
		SLEEP, IDLE, MOVING, ATTACKING, DEAD
	};

	float* GetMaxVelocity();
		
	void Death();

	bool CanMove();
	void ToggleCanMove();

	void Move(float fDeltaTime, int iDirection);
	void MoveTo(float fDeltaTime, float fX, float fY);

	void Stop(float fDeltaTime, int iDirection);
	void CompleteStop(float fDeltaTime);

	void DampenMovement();
};