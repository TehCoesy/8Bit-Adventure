// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

SpriteObject::SpriteObject() {
}

SpriteObject::~SpriteObject() {
}

void SpriteObject::SynchronizeBody() {
	if (m_iID != -1) {
		if (m_bSpriteChanged) {
			// ! Important (Box2D m_PhysicsBody origin is center of body)
			m_Sprite.setOrigin(sf::Vector2f(m_Sprite.getTexture()->getSize().x / 2, m_Sprite.getTexture()->getSize().y / 2));

			float fScaleX = m_fSizeP.x / m_Sprite.getTexture()->getSize().x;
			float fScaleY = m_fSizeP.y / m_Sprite.getTexture()->getSize().y;
			m_Sprite.setScale(sf::Vector2f(fScaleX, fScaleY));

			m_bSpriteChanged = false;
		}

		m_Sprite.setPosition(m_PhysicsBody->GetPosition().x * PIXELS_METERS, m_PhysicsBody->GetPosition().y * PIXELS_METERS);
		m_Sprite.setRotation(Radian2Degree(m_PhysicsBody->GetAngle()));
	}
}

void SpriteObject::SetSpriteChanged() {
	m_bSpriteChanged = true;
}

void SpriteObject::NewAnimation(std::string strName) {
	m_Animation = RM->GetAnimation(strName);
}

void SpriteObject::NewTexture(std::string strName) {
	m_StaticTexture = RM->GetTexture(strName);
}

void SpriteObject::Update(float fDeltaTime) {
}

void SpriteObject::Render(sf::RenderWindow* RenderWindow) {
}