#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Projectile : public DynamicObject {
private:
	Projectile(Projectile const&) = delete;
	Projectile& operator=(Projectile const&) = delete;

	std::string m_strProjectileType;

	int m_iParentID;
	ObjectType m_ParentType;
	
	int m_iFrameCount = 0;
public:
	Projectile();
	Projectile(std::string strName, b2Body* physicsBody, std::string strType, int iParentID, ObjectType parentType, b2Vec2 fSizeP);
	~Projectile();

	void SetParent(int iParentID, ObjectType parentType);

	void Move(float fDeltaTime, int iDirection) {
		// Disable applying force on Projectile
	}

	void MoveTo(float fDeltaTime, float fX, float fY) {
		// Disable applying force on Projectile
	}

	void Stop(float fDeltaTime, int iDirection) {
		// Disable applying force on Projectile
	}

	void CompleteStop(float fDeltaTime) {
		// Disable applying force on Projectile
	}

	void DampenMovement() {
		// Disable applying force on Projectile
	}

	void Death();
	void Destroy();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};