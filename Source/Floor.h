#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class Floor : public MyObject {
private:
public:
	Floor();
	Floor(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody);
	Floor(const Floor& cObject);
	~Floor();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);

	void MoveDown(float fDeltaTime);
	void MoveUp(float fDeltaTime);
	void MoveLeft(float fDeltaTime);
	void MoveRight(float fDeltaTime);
};