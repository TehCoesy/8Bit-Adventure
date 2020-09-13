// Precompiled Headers
#include "stdafx.h"

#include "Ground.h"

Ground::Ground() {
}

Ground::Ground(std::string strTextureName, int TileX, int TileY) {
	RM->GetTexture(strTextureName).Fetch(&m_Sprite);

	m_Sprite.setOrigin(sf::Vector2f(m_Sprite.getTexture()->getSize().x / 2, m_Sprite.getTexture()->getSize().y / 2));

	float fScaleX = TILE_SIZE / m_Sprite.getTexture()->getSize().x;
	float fScaleY = TILE_SIZE / m_Sprite.getTexture()->getSize().y;
	m_Sprite.setScale(sf::Vector2f(fScaleX, fScaleY));

	m_Sprite.setPosition(sf::Vector2f(TILE_SIZE * TileX, TILE_SIZE * TileY));
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