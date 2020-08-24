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

	m_fMaxVelocity = 5.0f;
}

Player::Player(const Player& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_Animation = cObject.m_Animation;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_Animation.Fetch(&m_Sprite);
	m_Animation.Play();

	m_fMaxVelocity = 5.0f;
}

Player::~Player() {

}

void Player::Update(float fDeltaTime) {
	if (m_iID != -1) {
		if (m_fCurrentVelocityX == 0.0f && m_fCurrentVelocityY == 0.0f) {
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
		else {
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