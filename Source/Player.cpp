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
}

Player::Player(const Player& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_StaticTexture.Fetch(&m_Sprite);
}

Player::~Player() {

}

void Player::Update(float fDeltaTime) {
	if (m_iID != -1) {
		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
	}
}

void Player::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		RenderWindow->draw(m_Sprite);
	}
}

void Player::MoveDown(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Player::MoveUp(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Player::MoveLeft(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Player::MoveRight(float fDeltaTime) {
	if (m_iID != -1) {

	}
}