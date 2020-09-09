// Precompiled Headers
#include "stdafx.h"

#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(int iID, std::string strName, std::string strEnemyType, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_Animation = RM->GetAnimation("SKELE_IDLE_DOWN");
	m_PhysicsBody = PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_fMaxVelocity = 1.0f;

	m_Animation.Fetch(&m_Sprite);

	m_ObjectType = ObjectType::ENEMY;
	m_bIsActive = true;
}

Enemy::Enemy(const Enemy& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_fMaxVelocity = 1.0f;

	m_StaticTexture.Fetch(&m_Sprite);

	m_bIsActive = true;
}

Enemy::~Enemy() {

}

void Enemy::Update(float fDeltaTime) {
/*	if (m_iID != -1) {
		SynchronizeBody();
		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
	}
	*/
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