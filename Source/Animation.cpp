// Precompiled Headers
#include "stdafx.h"

#include "Animation.h"

Animation::Animation(int iID, int iFrames, int iTimeSteps, std::string strName, std::vector<MyTexture> aAnimationFrames) {
	m_iID = iID;
	m_iFrameSteps = iTimeSteps;
	m_iFrameIndex = iFrames;
	m_strName = strName;
	m_AnimationFrames = aAnimationFrames;
}

Animation::~Animation() {

}

void Animation::Stop() {
	m_iFrameIndex = 0;
	m_bIsPlaying = false;
}

void Animation::Play() {
	m_bIsPlaying = true;
}

int Animation::GetID() {
	return m_iID;
}

void Animation::Update(float fDeltaTime) {

}

void Animation::Fetch(sf::Sprite* ObjectSprite) {

}

std::vector<MyTexture> Animation::GetAnimationFrames() {
	return m_AnimationFrames;
}