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
#include "SoundManager.h"
#include "Camera.h"

enum class ObjectType { OBJ, PLAYER, ENEMY, STATIC, MELEE, PROJECTILE, WALL };
enum class ObjectState { SPAWN, SLEEP, IDLE, MOVING, ATTACK, DEATH, DESTROYED};

class MyObject {
private:
	MyObject(MyObject const&) = delete;
	MyObject& operator=(MyObject const&) = delete;
protected:
	MyObject();
	~MyObject();

	void DestroyBody();

	// Object
	int m_iID = -1;
	std::string m_strName = "";

	ObjectType m_ObjectType = ObjectType::OBJ;
	ObjectState m_ObjectState = ObjectState::SPAWN;

	// Physics
	b2Vec2 m_fSizeP; // Object's size in pixels, for setting Sprite's origin
	b2Body* m_PhysicsBody;

	// States
	bool m_bIsActive = false;
public:
	// Identity
	int* GetID();
	std::string* GetName();

	ObjectState GetObjectState();
	ObjectType GetObjectType();

	// Physics
	b2Body* GetPhysicsBody();
	b2Vec2* GetSizeP(); // Get Object's size in pixels

	// States
	bool IsActive();
	void ToggleActive();

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* MainWindow);

	// Utility functions
	float Radian2Degree(float fRadian);
	float Degree2Radian(float fDegree);
};