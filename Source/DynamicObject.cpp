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

void DynamicObject::Move(float fDeltaTime, int iDirection) {
	if (m_iID != 1 && m_PhysicsBody) {
		// 0 = Down; 1 = Up; 2 = Left; 3 = Right;
		if (iDirection == 0) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityY != m_fMaxVelocity) {
				m_fCurrentVelocityY = m_fMaxVelocity;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 1) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityY != -m_fMaxVelocity) {
				m_fCurrentVelocityY = -m_fMaxVelocity;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 2) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityX != -m_fMaxVelocity) {
				m_fCurrentVelocityX = -m_fMaxVelocity;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 3) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityX != m_fMaxVelocity) {
				m_fCurrentVelocityX = m_fMaxVelocity;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
	}
}

void DynamicObject::Stop(float fDeltaTime, int iDirection) {
	if (m_iID != 1 && m_PhysicsBody) {
		// 0 = Down; 1 = Up; 2 = Left; 3 = Right;
		if (iDirection == 0) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityY != 0.0f && m_fCurrentVelocityY == m_fMaxVelocity) {
				m_fCurrentVelocityY = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 1) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityY != 0.0f && m_fCurrentVelocityY == -m_fMaxVelocity) {
				m_fCurrentVelocityY = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 2) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityX != 0.0f && m_fCurrentVelocityX == -m_fMaxVelocity) {
				m_fCurrentVelocityX = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 3) {
			m_iDirection = iDirection;
			if (m_fCurrentVelocityX != 0.0f && m_fCurrentVelocityX == m_fMaxVelocity) {
				m_fCurrentVelocityX = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
	}
}