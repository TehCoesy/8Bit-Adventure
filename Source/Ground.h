#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class Ground {
private:
	sf::Sprite m_Sprite;
public:
	Ground();
	Ground(std::string strTextureName, int TileX, int TileY);
	Ground(const Ground& cObject);
	~Ground();

	void Render(sf::RenderWindow* RenderWindow);
};