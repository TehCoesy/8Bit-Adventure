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


};