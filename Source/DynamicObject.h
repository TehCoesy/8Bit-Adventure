#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class DynamicObject : public MyObject {
protected:
	bool bIsMoving = false;

	int m_iDirection = 0; // 0 = Down; 1 = Up; 2 = Left; 3 = Right
	float m_fMaxVelocity = 0.0f;
	float m_fCurrentVelocityX = 0.0f, m_fCurrentVelocityY = 0.0f;
public:
	DynamicObject();
	~DynamicObject();

	float* GetMaxVelocity();

	void Move(float fDeltaTime, int iDirection);
	void Stop(float fDeltaTime, int iDirection);
};