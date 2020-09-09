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

	m_ObjectType = ObjectType::PLAYER;
	m_bIsActive = true;
}

Player::Player(const Player& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_Animation = cObject.m_Animation;
	m_PhysicsBody = cObject.m_PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_Animation.Fetch(&m_Sprite);
	m_Animation.Play();

	m_ObjectType = ObjectType::PLAYER;
	m_bIsActive = true;
}

Player::~Player() {

}

void Player::Update(float fDeltaTime) {
	if (m_iID != -1) {
		float fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
		float fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;

		if (fCurrentVelocityX == 0.0f && fCurrentVelocityY == 0.0f) {
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

		// Stop movement 
		Move(fDeltaTime, -1);
	}
}

void Player::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;

		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		//m_Sprite.setPosition(sf::Vector2f(200, 200));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}