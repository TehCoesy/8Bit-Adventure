// Precompiled Headers
#include "stdafx.h"

#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(int iID, std::string strName, std::string strEnemyType, b2Body* physicsBody, b2Vec2 fSizeP) {
	// Setup object's identity
	m_iID = iID;
	m_strName = strName;
	m_ObjectType = ObjectType::ENEMY;

	// Setup object's state
	m_ObjectState = ObjectState::IDLE;
	m_bIsActive = true;

	// Setup object's m_PhysicsBody
	m_PhysicsBody = physicsBody;
	m_PhysicsBody->SetUserData(this);

	// Setup object's Animation
	m_Animation = RM->GetAnimation("SKELE_IDLE_DOWN");
	m_Animation.Play();
	
	m_Animation.Fetch(&m_Sprite);

	// Setup sprite's size + origin
	m_fSizeP = fSizeP;
	SetSpriteChanged();

	SynchronizeBody();

	m_fMaxVelocity = 1.0f;
}

Enemy::~Enemy() {
	DestroyBody();
}

void Enemy::Death() {
	m_bIsDead = true;
}

void Enemy::Update(float fDeltaTime) {
	if (m_bIsDead) {
		CompleteStop(fDeltaTime);
		m_bCanMove = false;
		// Switch death animation
	}

	if (m_iID != -1) {
		float fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
		float fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;
		if (fCurrentVelocityX == 0.0f && fCurrentVelocityY == 0.0f) {
			if (m_iDirection == 0 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
		}
		else {
			if (m_iDirection == 0 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
		}

		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
		SynchronizeBody();

		//DampenMovement();
		// Stop movement 
		//Move(fDeltaTime, -1);
	}
}

void Enemy::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		fDistance = 9999999;
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;
		//m_Sprite.setPosition(sf::Vector2f(600, 600));
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}