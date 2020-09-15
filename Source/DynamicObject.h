#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

class DynamicObject : public SpriteObject {
private:
	DynamicObject(DynamicObject const&) = delete;
	DynamicObject& operator=(DynamicObject const&) = delete;

protected:
	//basic info
	float m_iHealth;
	int m_iScores;
	float m_iDamage;
	float max_iHealth;
	// Movement
	bool m_bMovingDown, m_bMovingUp, m_bMovingLeft, m_bMovingRight;
	int m_iDirection = 0; // 0 = Down; 1 = Up; 2 = Left; 3 = Right

	float m_fMaxVelocity = 5.0f;
	float m_fForce = 100.0f;

	bool m_bCanMove = true;
	bool m_bIsDead = false;
public:
	DynamicObject();
	~DynamicObject();

	float* GetMaxVelocity();
	int GetDirection();
		
	virtual void Spawn();
	virtual void Death();
	virtual void Destroy();
	virtual void Attack();
	virtual void Damaged(float damage);
	float getMaxHealth();



	bool CanMove();
	void ToggleCanMove();

	void Move(float fDeltaTime, int iDirection);
	void MoveTo(float fDeltaTime, float fX, float fY);

	void Stop(float fDeltaTime, int iDirection);
	void CompleteStop(float fDeltaTime);

	bool isDead();
	int getHealth();
	int getScores();
	void setScores(int score);
	int GetDamage();
	void SetDamage(int damage);

	// Utility
	enum Direction {
		DOWN = 0, UP = 1, LEFT = 2, RIGHT = 3
	};
};