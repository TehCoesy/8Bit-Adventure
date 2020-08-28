#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class DynamicObject : public MyObject {
protected:
	bool m_bMovingDown, m_bMovingUp, m_bMovingLeft, m_bMovingRight;
	int m_iDirection = 0; // 0 = Down; 1 = Up; 2 = Left; 3 = Right

	float m_fMaxVelocity = 5.0f;
	float m_fCurrentVelocityX = 0.0f, m_fCurrentVelocityY = 0.0f;

	bool bIsDead;
public:
	DynamicObject();
	~DynamicObject();

	enum Direction {
		DOWN = 0, UP = 1, LEFT = 2, RIGHT = 3
	};

	float* GetMaxVelocity();
		
	void Death();

	void Move(float fDeltaTime, int iDirection);
	void Stop(float fDeltaTime, int iDirection);
};