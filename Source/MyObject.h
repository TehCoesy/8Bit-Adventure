#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyTexture.h"
#include "Animation.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

class MyObject {
protected:
	int m_iID;
	std::string m_strName;

	sf::Sprite m_Sprite;
	sf::RectangleShape m_PhysicsBox;

	b2Body* m_PhysicsBody;

	MyTexture m_StaticTexture;
	Animation m_Animation;
public:
	MyObject();
	~MyObject();

	int* GetID();
	std::string* GetName();

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* RenderWindow);
};