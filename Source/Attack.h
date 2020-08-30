#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "SensorObject.h"

class Attack : public SensorObject {
private:
	int m_iSteps = 20, m_iCount = 0;

	sf::RectangleShape SensorBox;

	void Synchronize();
public:
	Attack();
	Attack(b2Body* SensorBody, float fX, float fY);
	Attack(const Attack& cObject);
	~Attack();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};