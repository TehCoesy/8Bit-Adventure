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

	m_Animation.Fetch(&m_Sprite);
	m_Animation.Play();

	m_fVelocity = 2.0f;
}

Player::Player(const Player& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_Animation = cObject.m_Animation;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_Animation.Fetch(&m_Sprite);
	m_Animation.Play();

	m_fVelocity = 2.0f;
}

Player::~Player() {

}

void Player::Update(float fDeltaTime) {
	if (m_iID != -1) {
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

void Player::MoveDown(float fDeltaTime) {
	if (m_iID != -1) {
		fVelY = 2.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::MoveUp(float fDeltaTime) {
	if (m_iID != -1) {
		fVelY = -2.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::MoveLeft(float fDeltaTime) {
	if (m_iID != -1) {
		fVelX = -2.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::MoveRight(float fDeltaTime) {
	if (m_iID != -1) {
		fVelX = 2.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::StopDown(float fDeltaTime) {
	if (m_iID != -1) {
		fVelY = 0.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::StopUp(float fDeltaTime) {
	if (m_iID != -1) {
		fVelY = 0.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::StopLeft(float fDeltaTime) {
	if (m_iID != -1) {
		fVelX = 0.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}

void Player::StopRight(float fDeltaTime) {
	if (m_iID != -1) {
		fVelX = 0.0f;
		m_PhysicsBody->SetLinearVelocity(b2Vec2(fVelX, fVelY));
	}
}