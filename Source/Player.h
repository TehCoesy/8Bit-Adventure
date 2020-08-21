#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class Player : public MyObject {
private:

public:
	Player();
	Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody);
	Player(const Player& cObject);
	~Player();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	void MoveDown(float fDeltaTime);
	void MoveUp(float fDeltaTime);
	void MoveLeft(float fDeltaTime);
	void MoveRight(float fDeltaTime);
};