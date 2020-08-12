#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "SFML/Graphics.hpp"

class Animation {
private:
	int m_iID = -1;
	int m_iFrameSteps = 10, m_iFrameIndex = 0;
	std::string m_strName = "";

	std::vector<sf::Texture> m_Sprites;

	bool m_bIsPlaying = false;
public:
	Animation();
	~Animation();

	void Stop();
	void Play();

	void Update(float fDeltaTime);
	void Fetch(sf::Sprite* ObjectSprite);
};