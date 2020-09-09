// Precompiled Headers
#include "stdafx.h"

#include "Boss.h"

Boss::Boss() {

}

Boss::Boss(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_Animation = RM->GetAnimation(strAnimationName);
	m_PhysicsBody = PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_Animation.Fetch(&m_Sprite);
}

Boss::Boss(const Boss& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_StaticTexture.Fetch(&m_Sprite);
}

Boss::~Boss() {

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