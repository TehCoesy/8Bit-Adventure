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

	// Graphics
	sf::Sprite m_Sprite;
	MyTexture m_StaticTexture;
	Animation m_Animation;

	b2Body* m_PhysicsBody;

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

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* MainWindow);
};