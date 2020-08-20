// Precompiled Headers
#include "stdafx.h"

#include "Animation.h"

Animation::Animation() {
}

Animation::Animation(int iID, int iFrames, int iTimeSteps, std::string strName, std::vector<MyTexture> aAnimationFrames) {
	m_iID = iID;
	m_iFrameSteps = iTimeSteps;
	m_iFrameID = m_iFrameIndex = m_AnimationFrames.at(0).GetID();
	m_strName = strName;
	m_AnimationFrames = aAnimationFrames;
}

Animation::~Animation() {
}

void Animation::Stop() {
	m_bIsPlaying = false;
}

void Animation::Play() {
	m_bIsPlaying = true;
}

int Animation::GetAnimationID() {
	return m_iID;
}



void Animation::Update(float fDeltaTime) {
	if (m_bIsPlaying == true)
	{
		if (m_iCount == m_iFrameSteps)
		{
			m_iCount = 0;
			m_iFrameIndex = 0;
		}
		else
		{
			m_iCount++;
			m_iFrameIndex++;
		}
		m_iFrameID = m_AnimationFrames.at(m_iFrameIndex).GetID();
	}
	else
	{
		m_iFrameID = m_AnimationFrames.at(0).GetID();
		m_iFrameIndex = 0;
		m_iCount = 0;
	}
}

void Animation::Fetch(sf::Sprite* ObjectSprite) {
}

std::vector<MyTexture> Animation::GetAnimationFrames() {
	return m_AnimationFrames;
}

int Animation::GetActiveFrameID() {
	return m_iFrameID;
}