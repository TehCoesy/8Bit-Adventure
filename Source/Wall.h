#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

class Wall : public SpriteObject {
private:
	Wall(Wall const&) = delete;
	Wall& operator=(Wall const&) = delete;

	int m_iTileX, m_iTileY;
	int m_iCordinateX, m_iCordinateY;
public:
	Wall();
	Wall(int iID, std::string strName, std::string strTextureName, b2Body* physicsBody, int iTileX, int iTileY, int iCorX, int iCorY);
	~Wall();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};