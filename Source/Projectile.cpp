// Precompiled Headers
#include "stdafx.h"

#include "Projectile.h"

Projectile::Projectile() {

}

Projectile::Projectile(std::string strName, b2Body* physicsBody, std::string strType, int iParentID, ObjectType parentType, b2Vec2 fSizeP) {
	// Setup object's identity
	m_iID = 0;
	m_strName = strName;
	m_ObjectType = ObjectType::PROJECTILE;

	// Setup object's state
	m_ObjectState = ObjectState::MOVING;
	m_bIsActive = true;

	// Setup object's m_PhysicsBody
	m_PhysicsBody = physicsBody;
	m_PhysicsBody->SetUserData(this);

	// Setup object's Animation
	m_strProjectileType = strType;
	if (m_strProjectileType == "ARROW") {
		m_Animation = RM->GetAnimation("ARROW");
	}
	else if (m_strProjectileType == "BULLET") {
		m_Animation = RM->GetAnimation("BULLET");
	}
	m_Animation.Play();

	m_Animation.Fetch(&m_Sprite);

	// Setup sprite's size + origin
	m_fSizeP = fSizeP;
	SetSpriteChanged();

	SynchronizeBody();
}

Projectile::~Projectile() {
	DestroyBody();
}

void Projectile::SetParent(int iParentID, ObjectType parentType) {
	m_iParentID = iParentID;
	m_ParentType = parentType;
}

void Projectile::Death() {
	if (m_ObjectState != ObjectState::DEATH && m_ObjectState != ObjectState::DESTROYED) {
		m_ObjectState = ObjectState::DEATH;
		if (m_strProjectileType == "ARROW") {
			m_Animation = RM->GetAnimation("ARROW_BREAK");
			SM->PlayEffectByName("ARROW_HIT");
		}

		if (m_Animation.IsRepeating()) {
			m_Animation.ToggleRepeat();
		}
	}
}

void Projectile::Destroy() {
	m_bIsActive = false;
	m_ObjectState = ObjectState::DESTROYED;
}

void Projectile::Update(float fDeltaTime) {
	if (m_ObjectState == ObjectState::DEATH) {
		CompleteStop(fDeltaTime);
		m_bCanMove = false;
		if (m_Animation.IsDone()) {
			Destroy();
		}
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