#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

// Local
#include "MyTexture.h"
#include "Animation.h"
#include "ResourceManager.h"
#include "Camera.h"

enum class ObjectType { OBJ, PLAYER, ENEMY, STATIC, MELEE, PROJECTILE };

class MyObject {
protected:
	MyObject();
	~MyObject();

	// Identity
	int m_iID = -1;
	ObjectType m_ObjectType = ObjectType::OBJ;
	std::string m_strName = "";

	// Physics
	b2Body* m_PhysicsBody;

	// States
	bool m_bIsActive = false;
public:
	// Identity
	int* GetID();
	std::string* GetName();
	ObjectType GetObjectType();

	// Physics
	b2Body* GetPhysicsBody();

	// States
	bool IsActive();
	void ToggleActive();

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* MainWindow);
};