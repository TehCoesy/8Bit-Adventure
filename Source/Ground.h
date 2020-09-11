#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class Ground {
private:
	Ground(Ground const&) = delete;
	Ground& operator=(Ground const&) = delete;

	sf::Sprite m_Sprite;
public:
	Ground();
	Ground(std::string strTextureName, int TileX, int TileY);
	~Ground();

	void Render(sf::RenderWindow* RenderWindow);
};