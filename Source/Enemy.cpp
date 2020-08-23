// Precompiled Headers
#include "stdafx.h"

#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_Animation = RM->GetAnimation(strAnimationName);
	m_PhysicsBody = PhysicsBody;

	m_Animation.Fetch(&m_Sprite);
}

Enemy::Enemy(const Enemy& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_StaticTexture.Fetch(&m_Sprite);
}

Enemy::~Enemy() {

}

void Enemy::Update(float fDeltaTime) {
	if (m_iID != -1) {
		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
	}
}

void Enemy::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		RenderWindow->draw(m_Sprite);
	}
}