// Precompiled Headers
#include "stdafx.h"

#include "Player.h"

Player::Player() {

}

Player::Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_Animation = RM->GetAnimation(strAnimationName);
	m_PhysicsBody = PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_Animation.Fetch(&m_Sprite);
	m_Animation.Play();
}

Player::Player(const Player& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_Animation = cObject.m_Animation;
	m_PhysicsBody = cObject.m_PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_Animation.Fetch(&m_Sprite);
	m_Animation.Play();
}

Player::~Player() {

}

void Player::Update(float fDeltaTime) {
	if (m_iID != -1) {
		if (m_bIsAttacking) {
			m_iCount++;
			if (m_iCount == m_iSteps) {
				m_bIsAttacking = false;
			}
		}

		if (m_fCurrentVelocityX == 0.0f && m_fCurrentVelocityY == 0.0f && !m_bIsAttacking) {
			if (m_iDirection == 0 && *m_Animation.GetName() != "PLAYER_IDLE_DOWN") {
				NewAnimation("PLAYER_IDLE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "PLAYER_IDLE_UP") {
				NewAnimation("PLAYER_IDLE_UP");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "PLAYER_IDLE_LEFT") {
				NewAnimation("PLAYER_IDLE_LEFT");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "PLAYER_IDLE_RIGHT") {
				NewAnimation("PLAYER_IDLE_RIGHT");
			}
		}
		else if (!m_bIsAttacking) {
			if (m_iDirection == 0 && *m_Animation.GetName() != "PLAYER_MOVE_DOWN") {
				NewAnimation("PLAYER_MOVE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "PLAYER_MOVE_UP") {
				NewAnimation("PLAYER_MOVE_UP");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "PLAYER_MOVE_LEFT") {
				NewAnimation("PLAYER_MOVE_LEFT");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "PLAYER_MOVE_RIGHT") {
				NewAnimation("PLAYER_MOVE_RIGHT");
			}
		}
		
		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
		SynchronizeBody();
	}
}

void Player::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		RenderWindow->draw(m_Sprite);
	}
}

void Player::MeleeAttack() {
	if (!m_bIsAttacking) {
		m_bIsAttacking = true;
		m_iCount = 0;
		if (m_iDirection == 0) {
			NewAnimation("PLAYER_DOWN_ATTACK");
		}
		else if (m_iDirection == 1) {
			NewAnimation("PLAYER_UP_ATTACK");
		}
		else if (m_iDirection == 2) {
			NewAnimation("PLAYER_LEFT_ATTACK");
		}
		else if (m_iDirection == 3) {
			NewAnimation("PLAYER_RIGHT_ATTACK");
		}
	}
}

void Player::Move(float fDeltaTime, int iDirection) {
	if (m_iID != 1 && m_PhysicsBody) {
		if (m_bIsAttacking) {
			m_fCurrentVelocityX = 0.0f;
			m_fCurrentVelocityY = 0.0f;
			m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			return;
		}
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

void Player::Stop(float fDeltaTime, int iDirection) {
	if (m_iID != 1 && m_PhysicsBody) {
		if (m_bIsAttacking) {
			m_fCurrentVelocityX = 0.0f;
			m_fCurrentVelocityY = 0.0f;
			m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			return;
		}
		// 0 = Down; 1 = Up; 2 = Left; 3 = Right;
		if (iDirection == 0) {
			if (m_fCurrentVelocityY != 0.0f && m_fCurrentVelocityY == m_fMaxVelocity) {
				m_fCurrentVelocityY = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 1) {
			if (m_fCurrentVelocityY != 0.0f && m_fCurrentVelocityY == -m_fMaxVelocity) {
				m_fCurrentVelocityY = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 2) {
			if (m_fCurrentVelocityX != 0.0f && m_fCurrentVelocityX == -m_fMaxVelocity) {
				m_fCurrentVelocityX = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
		if (iDirection == 3) {
			if (m_fCurrentVelocityX != 0.0f && m_fCurrentVelocityX == m_fMaxVelocity) {
				m_fCurrentVelocityX = 0.0f;
				m_PhysicsBody->SetLinearVelocity(b2Vec2(m_fCurrentVelocityX, m_fCurrentVelocityY));
			}
		}
	}
}