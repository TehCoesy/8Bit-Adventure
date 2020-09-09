// Precompiled Headers
#include "stdafx.h"

#include "Animation.h"

Animation::Animation() {

}

Animation::Animation(int iID, std::string strName, int iSteps, std::vector<MyTexture> graFrames) {
	m_iID = iID;
	m_strName = strName;
	m_iFrameSteps = iSteps;

	m_graFrames = graFrames;

	m_iFrameIndex = 0;

	Play();
}

Animation::Animation(const Animation& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;
	m_iFrameSteps = cObject.m_iFrameSteps;

	m_graFrames = cObject.m_graFrames;

	m_iFrameIndex = 0;

	Play();
}

Animation::~Animation() {
}

void Animation::Stop() {
	m_bIsPlaying = false;
}

void Animation::Play() {
	m_bIsPlaying = true;
}

int* Animation::GetID() {
	return &m_iID;
}

std::string* Animation::GetName() {
	return &m_strName;
}

void Animation::Update(float fDeltaTime) {
	if (m_bIsPlaying && m_iID != -1) {
		m_iCount++;
		if (m_iCount == m_iFrameSteps) {
			m_iCount = 0;
			if (m_iFrameIndex == m_graFrames.size() - 1) {
				m_iFrameIndex = 0;
			}
			else {
				m_iFrameIndex++;
			}
		}
	}
}

void Animation::Fetch(sf::Sprite* ObjectSprite) {
	if (m_iID != -1) {
		m_graFrames.at(m_iFrameIndex).Fetch(ObjectSprite);
	}
}