#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyTexture.h"
#include "Animation.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"
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

	MyTexture m_Texture;
	std::vector<Animation> m_AnimationList{};
	int m_iDirection = 1; //down
	float m_fVelocity = 0.0f;
public:
	MyObject();
	~MyObject();

	int* GetID();
	std::string* GetName();

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* MainWindow);

	void SetDirection(int iDirection);
	void AddAnimation(int iAnimID);
};