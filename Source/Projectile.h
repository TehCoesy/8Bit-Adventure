#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "DynamicObject.h"

class Projectile : public DynamicObject {
private:
	std::string m_strProjectileType;
	ObjectType m_ParentType;
	int m_iParentID;
public:
	Projectile();
	Projectile(int iID, std::string strName, b2Body* physicsBody, std::string strType);
	Projectile(const Projectile& cObject);
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
};