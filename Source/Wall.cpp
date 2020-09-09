// Precompiled Headers
#include "stdafx.h"

#include "Wall.h"

Wall::Wall() {

}

Wall::Wall(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody, int iTileX, int iTileY, int iCorX, int iCorY) {
	m_iID = iID;
	m_strName = strName;
	m_iTileX = iTileX;
	m_iTileY = iTileY;
	m_iCordinateX = iCorX;
	m_iCordinateY = iCorY;

	m_StaticTexture = RM->GetTexture(strTextureName);
	//m_StaticTexture.SetRepeated(true);
	m_StaticTexture.Fetch(&m_Sprite);
	//m_Sprite.setTextureRect({ 0, 0, iTileX, iTileY });
	m_PhysicsBody = PhysicsBody;
	m_PhysicsBody->SetUserData(this);


	m_bIsActive = true;

	SynchronizeBody();
}

Wall::Wall(const Wall& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_StaticTexture.Fetch(&m_Sprite);

	m_bIsActive = true;

	SynchronizeBody();
}

Wall::~Wall() {

}

void Wall::Update(float fDeltaTime) {
	if (m_iID != -1) {
		SynchronizeBody();
	}
}

void Wall::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;

		
		for (int i = 0; i < m_iTileX; i++) {
			for (int k = 0; k < m_iTileY; k++) {
				m_Sprite.setPosition(sf::Vector2f(m_iCordinateX * TILE_SIZE + MainCamera->GetCameraVector().x + i * TILE_SIZE , m_iCordinateY * TILE_SIZE + MainCamera->GetCameraVector().y + k * TILE_SIZE));
				RenderWindow->draw(m_Sprite);
			}
		}

		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}
