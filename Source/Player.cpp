// Precompiled Headers
#include "stdafx.h"

#include "Player.h"

Player::Player() {

}

Player::Player(int iID, std::string strName, std::string strAnimationName, b2Body* physicsBody, b2Vec2 fSizeP, int health, int scores, int damage) {
	// Always do the following:
	// + Setup object's identity
	// + Setup object's state
	// + m_bIsActive / m_bCanMove / m_bIsDead;
	// + Setup object's m_PhysicsBody
	// + Setup object's Animation / Texture
	// + Setup sprite's m_fSizeP and setup proper origin (!Important) (call SetSpriteChanged() and SynchronizeBody())
	// + Setup m_fMaxVelocity (if needed) (default is 5.0f)
	
	// Setup object's identity
	m_iID = iID;
	m_strName = strName;
	m_ObjectType = ObjectType::PLAYER;

	// Setup object's state
	m_ObjectState = ObjectState::IDLE;
	m_bIsActive = true;

	// Setup object's m_PhysicsBody
	m_PhysicsBody = physicsBody;
	m_PhysicsBody->SetUserData(this);

	// Setup object's Animation
	m_Animation = RM->GetAnimation(strAnimationName);
	m_Animation.Play();

	m_Animation.Fetch(&m_Sprite);

	// Setup sprite's size + origin
	m_fSizeP = fSizeP;
	SetSpriteChanged();

	m_iHealth = health;
	max_iHealth = health;
	m_iScores = scores;
	m_iDamage = damage;
	SynchronizeBody();
}

Player::~Player() {
	DestroyBody();
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
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}

int Player::getMaxHealth() {
	return max_iHealth;
}