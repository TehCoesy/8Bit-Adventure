// Precompiled Headers
#include "stdafx.h"

#include "Ground.h"

Ground::Ground() {

}

Ground::Ground(std::string strTextureName, int TileX, int TileY) {
	RM->GetTexture(strTextureName).Fetch(&m_Sprite);

	m_Sprite.setPosition(sf::Vector2f(TILE_SIZE * TileX, TILE_SIZE * TileY));

	m_Sprite.setScale(sf::Vector2f(4.0f, 4.0f));
}

Ground::Ground(const Ground& cObject) {
	m_Sprite = cObject.m_Sprite;
}

Ground::~Ground() {

}

void Ground::Render(sf::RenderWindow* RenderWindow) {
	RenderWindow->draw(m_Sprite);
}