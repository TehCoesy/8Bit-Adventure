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

class MyObject {
protected:
	// Identity
	int m_iID = -1;
	std::string m_strName = "";

	// Properties
	float m_fHealth = 100.0f;
	int m_iDirection = 0; // 0 = Down; 1 = Up; 2 = Left; 3 = Right
	float m_fVelocity = 0.0f;

	// Graphics
	sf::Sprite m_Sprite;
	sf::RectangleShape m_PhysicsBox;

	b2Body* m_PhysicsBody;

	MyTexture m_StaticTexture;
	Animation m_Animation;

	// Fetch new Animation / Texture from RM
	void NewAnimation(std::string strName);
	void NewTexture(std::string strName);

	// Synchronize Sprite with PhysicsBody
	void SynchronizeBody();
public:
	MyObject();
	~MyObject();
	
	// Identity
	int* GetID();
	std::string* GetName();

	// Properties
	float* GetHealth();
	float* GetVel();

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* MainWindow);

	// Movement (does nothing for StaticObjects)
	virtual void MoveDown(float fDeltaTime);
	virtual void MoveUp(float fDeltaTime);
	virtual void MoveLeft(float fDeltaTime);
	virtual void MoveRight(float fDeltaTime);

	virtual void StopDown(float fDeltaTime);
	virtual void StopUp(float fDeltaTime);
	virtual void StopLeft(float fDeltaTime);
	virtual void StopRight(float fDeltaTime);
};