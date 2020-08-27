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

EnemySpawner::EnemySpawner(const EnemySpawner& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	m_StaticTexture.Fetch(&m_Sprite);

	SynchronizeBody();
}

EnemySpawner::~EnemySpawner() {

}

void EnemySpawner::Update(float fDeltaTime) {
	if (m_iID != -1) {
		SynchronizeBody();
	}
}

void EnemySpawner::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		RenderWindow->draw(m_Sprite);
	}
}