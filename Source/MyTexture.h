#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "SFML/Graphics.hpp"

class MyTexture {
private:
	int m_iID = -1;
	std::string m_strName = "";

	sf::Texture m_Texture;
public:
	MyTexture();
	MyTexture(int iID, std::string strName, sf::Texture Texture);
	MyTexture(const MyTexture& cMyTexture);
	~MyTexture();

	int* GetID();
	std::string* GetName();

	sf::Texture GetTexture();
	void Fetch(sf::Sprite* ObjectSprite);
};