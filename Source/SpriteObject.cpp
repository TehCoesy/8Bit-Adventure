// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

SpriteObject::SpriteObject() {

}

SpriteObject::~SpriteObject() {

}

void SpriteObject::SynchronizeBody() {
	if (m_iID != -1 && m_bIsActive) {
		m_Sprite.setPosition(m_PhysicsBody->GetPosition().x * PIXELS_METERS, m_PhysicsBody->GetPosition().y * PIXELS_METERS);
		m_Sprite.setRotation(m_PhysicsBody->GetAngle() * 180 / b2_pi);
	}
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