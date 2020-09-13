// Precompiled Headers
#include "stdafx.h"

#include "Boss.h"

Boss::Boss() {

}

Boss::Boss(int iID, std::string strName, std::string strAnimationName, b2Body* physicsBody, b2Vec2 fSizeP) {
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
	m_Animation = RM->GetAnimation(strAnimationName);
	m_Animation.Play();

	m_Animation.Fetch(&m_Sprite);

	// Setup sprite's size + origin
	m_fSizeP = fSizeP;
	SetSpriteChanged();

	SynchronizeBody();

	m_fMaxVelocity = 2.0f;
}

Boss::~Boss() {
	DestroyBody();
}

void Boss::Update(float fDeltaTime) {
	if (m_iID != -1) {
		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
	}
}

void Boss::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;

		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}