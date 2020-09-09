#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "SFML/Graphics.hpp"

class MyTexture {
private:
	int m_iID = -1;
	std::string m_strName = "";

	float m_fDesiredX = TILE_SIZE, m_fDesiredY = TILE_SIZE;
	sf::Texture* m_Texture;
public:
	MyTexture();
	MyTexture(int iID, std::string strName, sf::Texture* Texture);
	MyTexture(const MyTexture& cMyTexture);
	~MyTexture();

	int* GetID();
	std::string* GetName();
	void SetRepeated(bool a);

	void SetScale(float fScaleX, float fScaleY);

	void Fetch(sf::Sprite* ObjectSprite);
};