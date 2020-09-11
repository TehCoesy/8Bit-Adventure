#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "SensorObject.h"

class Weapon : public SensorObject {
private:
	Weapon(Weapon const&) = delete;
	Weapon& operator=(Weapon const&) = delete;

	int m_iSteps = 20, m_iCount = 0;

	sf::RectangleShape SensorBox;

	void Synchronize();
public:
	Weapon();
	Weapon(b2Body* SensorBody, float fX, float fY);
	~Weapon();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};