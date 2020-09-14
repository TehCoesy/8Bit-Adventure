#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"
#include "Player.h"

class Enemy : public DynamicObject {
private:
	Enemy(Enemy const&) = delete;
	Enemy& operator=(Enemy const&) = delete;
	Player* player;
	int ping;
public:
	float fDistance;
	float fDistanceX;
	float fDistanceY;

	Enemy();
	Enemy(int iID, std::string strName, std::string strEnemyType, b2Body* physicsBody, b2Vec2 fSizeP, int health, int scores, int damage,Player* player);
	~Enemy();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	// Enemy types
	enum {
		SKELE, GHOST, DARKELF
	};
};