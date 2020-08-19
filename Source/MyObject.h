#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"

class MyObject {
protected:
	sf::Sprite m_Sprite;
	MyTexture m_Texture;
	std::vector<Animation> m_AnimationList{};
	int m_iDirection = 1; //down
	float m_fVelocity = 0.0f;
public:
	MyObject();
	~MyObject();

	void CreateObject(sf::Texture Texture);

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* MainWindow);

	void SetDirection(int iDirection);
	void AddAnimation(int iAnimID);
};