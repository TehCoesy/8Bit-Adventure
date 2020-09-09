// Precompiled Headers
#include "stdafx.h"

#include "Ground.h"

Ground::Ground() {

}

Ground::Ground(std::string strTextureName, int TileX, int TileY) {
	RM->GetTexture(strTextureName).Fetch(&m_Sprite);

	m_Sprite.setPosition(sf::Vector2f(TILE_SIZE * TileX, TILE_SIZE * TileY));
}

Ground::Ground(const Ground& cObject) {
	m_Sprite = cObject.m_Sprite;
}

Ground::~Ground() {

}

void Ground::Render(sf::RenderWindow* RenderWindow) {
	float WorldPositionX = m_Sprite.getPosition().x;
	float WorldPositionY = m_Sprite.getPosition().y;

	m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
	RenderWindow->draw(m_Sprite);
	m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
}