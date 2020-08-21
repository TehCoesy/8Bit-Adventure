#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "SFML/Graphics.hpp"

class Animation {
private:
	int m_iID = -1;
	std::string m_strName = "";
	int m_iFrameSteps = 10, m_iFrameIndex = 0, m_iCount = 0;
	
	std::vector<sf::Texture*> m_AnimationFrames;

	bool m_bIsPlaying = false;
public:
	Animation();
	Animation(int iID, std::string strName, int iSteps, std::vector<sf::Texture*> AnimationFrames);
	Animation(const Animation& cObject);
	~Animation();

	void Stop();
	void Play();

	int* GetID();
	std::string* GetName();

	void Update(float fDeltaTime);
	void Fetch(sf::Sprite* ObjectSprite);
};