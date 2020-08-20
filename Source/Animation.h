#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "SFML/Graphics.hpp"
#include "MyTexture.h"

class Animation {
private:
	int m_iID = -1;
	int m_iFrameSteps = 10, m_iFrameIndex = 0;
	std::string m_strName = "";

	std::vector<MyTexture> m_AnimationFrames;

	bool m_bIsPlaying = false;
public:
	Animation(int iID, int iFrames, int iTimeSteps, std::string strName, std::vector<MyTexture> aAnimationFrames);
	~Animation();

	void Stop();
	void Play();

	int GetID();

	void Update(float fDeltaTime);
	void Fetch(sf::Sprite* ObjectSprite);
	std::vector<MyTexture> GetAnimationFrames();
};