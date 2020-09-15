#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyTexture.h"

class Animation {
private:
	int m_iID = -1;
	std::string m_strName = "";
	int m_iFrameSteps = 10, m_iFrameIndex = 0, m_iCount = 0;
	
	std::vector<MyTexture> m_graFrames;

	bool m_bIsPlaying = false;
	bool m_bRepeat = true;

	// Blinking
	bool m_bBlinking = false, m_bTransparent = false;
	int m_iFrameCount = 0, m_iFrameDuration = 0, m_iBlinkFrames = 50;
public:
	Animation();
	Animation(int iID, std::string strName, int iSteps, std::vector<MyTexture> AnimationFrames);
	Animation(const Animation& cObject);
	~Animation();

	void Stop();
	void Play();

	int* GetID();
	std::string* GetName();

	void Update(float fDeltaTime);
	void Fetch(sf::Sprite* ObjectSprite);

	bool IsRepeating();
	void ToggleRepeat();
	bool IsDone();

	// Blinking
	void BlinkForFrames(int iFrames);
	void BlinkOnce();
};