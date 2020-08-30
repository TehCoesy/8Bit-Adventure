#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Enemy : public DynamicObject {
public:
	enum {
		SKELE, GHOST, DARKELF
	};

	Enemy();
	Enemy(int iID, std::string strName, std::string strEnemyType, b2Body* PhysicsBody);
	Enemy(const Enemy& cObject);
	~Enemy();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};