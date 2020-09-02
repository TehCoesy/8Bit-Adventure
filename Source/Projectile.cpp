// Precompiled Headers
#include "stdafx.h"

#include "Projectile.h"

Projectile::Projectile() {

}

Projectile::Projectile(int iID, std::string strName, b2Body* physicsBody, std::string strType) {
	m_iID = iID;
	m_strName = strName;

	m_PhysicsBody = physicsBody;

	m_strProjectileType = strType;
	if (m_strProjectileType == "ARROW") {
		m_StaticTexture = RM->GetTexture("ARROW");
	}
	else if (m_strProjectileType == "BULLET") {
		m_StaticTexture = RM->GetTexture("BULLET");
	}

	m_StaticTexture.Fetch(&m_Sprite);

	m_ObjectType = ObjectType::PROJECTILE;
	m_bIsActive = true;
}

Projectile::Projectile(const Projectile& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_PhysicsBody = cObject.m_PhysicsBody;

	m_strProjectileType = cObject.m_strProjectileType;
	if (m_strProjectileType == "ARROW") {
		m_StaticTexture = RM->GetTexture("ARROW");
	}
	else if (m_strProjectileType == "BULLET") {
		m_StaticTexture = RM->GetTexture("BULLET");
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