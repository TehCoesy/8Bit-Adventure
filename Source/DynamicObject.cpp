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

void DynamicObject::Spawn() {

}

void DynamicObject::Death() {

}

void DynamicObject::Despawn() {

}

void DynamicObject::Attack() {

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

		// 0 = Down; 1 = Up; 2 = Left; 3 = Right;
		if (iDirection == 0) {
			m_iDirection = iDirection;
			m_bMovingDown = true;

			if (fCurrentVelocityY < m_fMaxVelocity) {
				float fForce = 100.0f;
				m_PhysicsBody->ApplyForce(b2Vec2(0.0f, fForce), m_PhysicsBody->GetWorldCenter(), true);
			}
		}
		if (iDirection == 1) {
			m_iDirection = iDirection;
			m_bMovingUp = true;

			if (fCurrentVelocityY > -m_fMaxVelocity) {
				float fForce = -100.0f;
				m_PhysicsBody->ApplyForce(b2Vec2(0.0f, fForce), m_PhysicsBody->GetWorldCenter(), true);
			}
		}
		if (iDirection == 2) {
			m_iDirection = iDirection;
			m_bMovingLeft = true;

			if (fCurrentVelocityX > -m_fMaxVelocity) {
				float fForce = -100.0f;
				m_PhysicsBody->ApplyForce(b2Vec2(fForce, 0.0f), m_PhysicsBody->GetWorldCenter(), true);
			}
		}
		if (iDirection == 3) {
			m_iDirection = iDirection;
			m_bMovingRight = true;

			if (fCurrentVelocityX < m_fMaxVelocity) {
				float fForce = 100.0f;
				m_PhysicsBody->ApplyForce(b2Vec2(fForce, 0.0f), m_PhysicsBody->GetWorldCenter(), true);
			}
		}
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
		// 0 = Down; 1 = Up; 2 = Left; 3 = Right;
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
	}
}

void DynamicObject::CompleteStop(float fDeltaTime) {
	m_PhysicsBody->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

void DynamicObject::DampenMovement() {
	float fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
	float fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;

	if (!m_bMovingDown && !m_bMovingUp && std::fabsf(fCurrentVelocityY) < 10.0f) {
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fCurrentVelocityX, 0.0f));
	}

	fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
	fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;

	if (!m_bMovingLeft && !m_bMovingRight && std::fabsf(fCurrentVelocityX) < 10.0f) {
		m_PhysicsBody->SetLinearVelocity(b2Vec2(0.0f, fCurrentVelocityY));
	}

	m_bMovingDown = false; m_bMovingUp = false; m_bMovingLeft = false; m_bMovingRight = false;
}