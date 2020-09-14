// Precompiled Headers
#include "stdafx.h"

#include "DynamicObject.h"

DynamicObject::DynamicObject() {
}

DynamicObject::~DynamicObject() {
}

float* DynamicObject::GetMaxVelocity() {
	return &m_fMaxVelocity;
}

int DynamicObject::GetDirection() {
	return m_iDirection;
}

void DynamicObject::Spawn() {

}

void DynamicObject::Death() {

}

void DynamicObject::Destroy() {
	m_bIsActive = false;
	m_ObjectState = ObjectState::DESTROYED;
}

void DynamicObject::Attack() {

}

void DynamicObject::Damaged(int damage) {
	m_Animation.BlinkForFrames(100);
	this->m_iHealth -= damage;
	if (this->m_iHealth < 0) this->m_iHealth = 0;
}

bool DynamicObject::CanMove() {
	return m_bCanMove;
}

void DynamicObject::ToggleCanMove() {
	m_bCanMove = !m_bCanMove;
}

void DynamicObject::Move(float fDeltaTime, int iDirection) {
	if (m_iID != 1 && m_bIsActive && m_bCanMove && !m_bIsDead) {
		float fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
		float fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;

		// 0 = Down; 1 = Up; 2 = Left; 3 = Right for iDirection;
		b2Vec2 fCurrentVelocity = m_PhysicsBody->GetLinearVelocity();
		b2Vec2 fDesiredVelocity = b2Vec2(0.0f, 0.0f);

		switch (iDirection) {
		case 0: m_bMovingDown = true; break;
		case 1: m_bMovingUp = true; break;
		case 2: m_bMovingLeft = true; break;
		case 3: m_bMovingRight = true; break;
		}

		if (m_bMovingDown) {
			m_iDirection = 0;
			fDesiredVelocity.y = m_fMaxVelocity; 
		}
		if (m_bMovingUp) {
			m_iDirection = 1;
			fDesiredVelocity.y = -m_fMaxVelocity;
		}
		if (m_bMovingLeft) {
			m_iDirection = 2;
			fDesiredVelocity.x = -m_fMaxVelocity;
		}
		if (m_bMovingRight) {
			m_iDirection = 3;
			fDesiredVelocity.x = m_fMaxVelocity;
		}

		b2Vec2 fVelChange = b2Vec2(fDesiredVelocity.x - fCurrentVelocity.x, fDesiredVelocity.y - fCurrentVelocity.y);
		float fImpulseX = m_PhysicsBody->GetMass() * fVelChange.x;
		float fImpulseY = m_PhysicsBody->GetMass() * fVelChange.y;

		m_PhysicsBody->ApplyLinearImpulse(b2Vec2(fImpulseX, fImpulseY), m_PhysicsBody->GetWorldCenter(), true);
	}
}

void DynamicObject::MoveTo(float fDeltaTime, float fX, float fY) {
	if (m_iID != 1 && m_bIsActive && m_bCanMove && !m_bIsDead) {
		float fDiffX = std::fabsf(m_PhysicsBody->GetPosition().x - fX);
		float fDiffY = std::fabsf(m_PhysicsBody->GetPosition().y - fY);
	}
}

void DynamicObject::Stop(float fDeltaTime, int iDirection) {
	if (m_iID != 1 && m_PhysicsBody) {
		// 0 = Down; 1 = Up; 2 = Left; 3 = Right; 4= all direction;

		if (iDirection == 0) {
			m_bMovingDown = false;
		}
		if (iDirection == 1) {
			m_bMovingUp = false;
		}
		if (iDirection == 2) {
			m_bMovingLeft = false;
		}
		if (iDirection == 3) {
			m_bMovingRight = false;
		}
		if (iDirection == 4) {
			m_bMovingDown = false;
			m_bMovingUp = false;
			m_bMovingLeft = false;
			m_bMovingRight = false;
		}
	}
}

void DynamicObject::CompleteStop(float fDeltaTime) {
	m_PhysicsBody->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

bool DynamicObject::isDead()
{
	return m_bIsDead;
}

int DynamicObject::getHealth()
{
	return m_iHealth;
}
int DynamicObject::getScores()
{
	return m_iScores;
}
void DynamicObject::setScores(int score)
{
	this->m_iScores = score;
}


int DynamicObject::GetDamage()
{
	return m_iDamage;
}

void DynamicObject::SetDamage(int damage)
{
	this->m_iDamage = damage;
}
