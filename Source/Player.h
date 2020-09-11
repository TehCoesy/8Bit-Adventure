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

	// Debug
	bool m_bDebugDraw = true;
	sf::RectangleShape m_DebugBox;
public:
	Player();
	Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody, b2Vec2 fSizeP);
	~Player();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};