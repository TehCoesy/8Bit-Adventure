// Precompiled Headers
#include "stdafx.h"

#include "Projectile.h"

Projectile::Projectile() {

}

Projectile::Projectile(std::string strName, b2Body* physicsBody, std::string strType) {
	m_iID = 0;
	m_strName = strName;

	m_PhysicsBody = physicsBody;

	m_strProjectileType = strType;
	if (m_strProjectileType == "ARROW") {
		m_Animation = RM->GetAnimation("ARROW");
	}
	else if (m_strProjectileType == "BULLET") {
		m_Animation = RM->GetAnimation("BULLET");
	}

	m_StaticTexture.Fetch(&m_Sprite);

	m_ObjectType = ObjectType::PROJECTILE;
	m_bIsActive = true;
}

Projectile::Projectile(const Projectile& cObject) {
	m_iID = 0;
	m_strName = cObject.m_strName;

	m_PhysicsBody = cObject.m_PhysicsBody;

	m_strProjectileType = cObject.m_strProjectileType;
	if (m_strProjectileType == "ARROW") {
		m_Animation = RM->GetAnimation("ARROW");
	}
	else if (m_strProjectileType == "BULLET") {
		m_Animation = RM->GetAnimation("BULLET");
	}

	m_StaticTexture.Fetch(&m_Sprite);

	m_ObjectType = ObjectType::PROJECTILE;
	m_bIsActive = true;

	m_iParentID = cObject.m_iParentID;
	m_ParentType = cObject.m_ParentType;
}

Projectile::~Projectile() {

}

void Projectile::SetParent(int iParentID, ObjectType parentType) {
	m_iParentID = iParentID;
	m_ParentType = parentType;
}

void Projectile::Update(float fDeltaTime) {
	m_Animation.Update(fDeltaTime);
	m_Animation.Fetch(&m_Sprite);
	SynchronizeBody();
}

void Projectile::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;

		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
	}
}