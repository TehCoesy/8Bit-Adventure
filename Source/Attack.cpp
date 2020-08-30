// Precompiled Headers
#include "stdafx.h"

#include "Attack.h"

Attack::Attack() {

}

Attack::Attack(b2Body* SensorBody, float fX, float fY) {
	m_iID = 0;
	m_PhysicsBody = SensorBody;
	SensorBox = sf::RectangleShape(sf::Vector2f(fX, fY));
}

Attack::Attack(const Attack& cObject) {
	m_iID = 0;
	m_PhysicsBody = cObject.m_PhysicsBody;
}

Attack::~Attack() {

}

void Attack::Synchronize() {
	SensorBox.setPosition(m_PhysicsBody->GetPosition().x * PIXELS_METERS, m_PhysicsBody->GetPosition().y * PIXELS_METERS);
}

void Attack::Update(float fDeltaTime) {
	m_iCount++;
	if (m_iCount == m_iSteps) {
		if (IsActive()) ToggleActive();
	}
}

void Attack::Render(sf::RenderWindow* RenderWindow) {
	Synchronize();
	RenderWindow->draw(SensorBox);
}