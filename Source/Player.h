#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"
#include "SoundManager.h"

class Player : public DynamicObject {
private:
	Player(Player const&) = delete;
	Player& operator=(Player const&) = delete;
	int max_iHealth;

	// Debug
	bool m_bDebug = false;
	sf::RectangleShape m_DebugBox;
	sf::CircleShape m_DebugCircle;
public:
	Player();
	Player(int iID, std::string strName, std::string strAnimationName, b2Body* physicsBody, b2Vec2 fSizeP, int health, int scores, int damage);
	~Player();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
	int getMaxHealth();
};