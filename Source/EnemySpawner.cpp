// Precompiled Headers
#include "stdafx.h"

#include "EnemySpawner.h"

EnemySpawner::EnemySpawner() {

}

EnemySpawner::EnemySpawner(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_StaticTexture = RM->GetTexture(strTextureName);
	m_PhysicsBody = PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_StaticTexture.Fetch(&m_Sprite);

	SynchronizeBody();
}

EnemySpawner::~EnemySpawner() {
	DestroyBody();
}

void EnemySpawner::Update(float fDeltaTime) {
	if (m_iID != -1) {
		SynchronizeBody();
	}
}

void EnemySpawner::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;

		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}