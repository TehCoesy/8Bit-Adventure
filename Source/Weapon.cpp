// Precompiled Headers
#include "stdafx.h"

#include "Weapon.h"

Weapon::Weapon() {

}

Weapon::Weapon(b2Body* SensorBody, float fX, float fY) {
	m_iID = 0;
	m_PhysicsBody = SensorBody;
	SensorBox = sf::RectangleShape(sf::Vector2f(fX, fY));
}

Weapon::~Weapon() {
	DestroyBody();
}

void Weapon::Synchronize() {
	SensorBox.setPosition(m_PhysicsBody->GetPosition().x * PIXELS_METERS, m_PhysicsBody->GetPosition().y * PIXELS_METERS);
}

void Weapon::Update(float fDeltaTime) {
	m_iCount++;
	if (m_iCount == m_iSteps) {
		if (IsActive()) ToggleActive();
	}
}

void Weapon::Render(sf::RenderWindow* RenderWindow) {
	Synchronize();
	RenderWindow->draw(SensorBox);
}