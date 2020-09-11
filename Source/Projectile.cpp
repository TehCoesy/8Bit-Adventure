// Precompiled Headers
#include "stdafx.h"

#include "Projectile.h"

Projectile::Projectile() {

}

Projectile::Projectile(std::string strName, b2Body* physicsBody, std::string strType) {
	m_iID = 0;
	m_strName = strName;

	m_PhysicsBody = physicsBody;
	m_PhysicsBody->SetUserData(this);

	m_ObjectType = ObjectType::PROJECTILE;

	m_strProjectileType = strType;
	if (m_strProjectileType == "ARROW") {
		m_Animation = RM->GetAnimation("ARROW");
	}
	else if (m_strProjectileType == "BULLET") {
		m_Animation = RM->GetAnimation("BULLET");
	}

	m_bIsActive = true;

	m_StaticTexture.Fetch(&m_Sprite);
}

Projectile::~Projectile() {
	DestroyBody();
}

void Projectile::SetParent(int iParentID, ObjectType parentType) {
	m_iParentID = iParentID;
	m_ParentType = parentType;
}

void Projectile::Death() {
	m_ObjectState = ObjectState::DEATH;
}

void Projectile::Destroy() {
	m_bIsActive = false;
	m_ObjectState = ObjectState::DESTROYED;
}

void Projectile::Update(float fDeltaTime) {
	if (m_ObjectState == ObjectState::DEATH) {
		CompleteStop(fDeltaTime);
		m_bCanMove = false;
		Destroy();
	}

	m_Animation.Update(fDeltaTime);
	m_Animation.Fetch(&m_Sprite);
	SynchronizeBody();

	m_iFrameCount++;
	if (m_iFrameCount == 150) {
		Death();
	}
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