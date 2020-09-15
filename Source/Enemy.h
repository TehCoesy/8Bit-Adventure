#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"
#include "Player.h"
#include "SettingArg.h"

class Enemy : public DynamicObject {
private:
	Enemy(Enemy const&) = delete;
	Enemy& operator=(Enemy const&) = delete;
	Player* player;
	int ping;
	int m_iFrameCount = 0;

	// Debug
	bool m_bDebug = false;
	sf::RectangleShape m_DebugBox;
	sf::CircleShape m_DebugCircle;
public:
	float fDistance;
	float fDistanceX;
	float fDistanceY;

	Enemy();
	Enemy(int iID, std::string strName, std::string strEnemyType, b2Body* physicsBody, b2Vec2 fSizeP, int health, int scores, int damage,Player* player);
	~Enemy();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	void Damaged(int damage);
	void Death();
	void Destroy();

	// Enemy types
	enum {
		SKELE, GHOST, DARKELF
	};
};