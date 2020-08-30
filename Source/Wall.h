#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

class Wall : public SpriteObject {
private:
public:
	Wall();
	Wall(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody);
	Wall(const Wall& cObject);
	~Wall();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};