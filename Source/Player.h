#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class Player : public MyObject {
private:
	float fVelX = 0.0f, fVelY = 0.0f;
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

	void StopDown(float fDeltaTime);
	void StopUp(float fDeltaTime);
	void StopLeft(float fDeltaTime);
	void StopRight(float fDeltaTime);
};