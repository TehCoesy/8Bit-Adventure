// Precompiled Headers
#include "stdafx.h"

#include "Animation.h"

Animation::Animation() {

}

Animation::Animation(int iID, std::string strName, int iSteps, std::vector<sf::Texture*> AnimationFrames) {
	m_iID = iID;
	m_strName = strName;
	m_iFrameSteps = iSteps;

	m_AnimationFrames = AnimationFrames;

	m_iFrameIndex = 0;

	Play();
}

Animation::Animation(const Animation& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;
	m_iFrameSteps = cObject.m_iFrameSteps;

	m_AnimationFrames = cObject.m_AnimationFrames;

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
			if (m_iFrameIndex == m_AnimationFrames.size() - 1) {
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
		sf::Texture* Texture = m_AnimationFrames.at(m_iFrameIndex);
		ObjectSprite->setTexture(*m_AnimationFrames.at(m_iFrameIndex));

		if (Texture->getSize().x == 32 && Texture->getSize().y == 32) {
			ObjectSprite->setScale(sf::Vector2f(2.0f, 2.0f));
		}
		else if (Texture->getSize().x == 16 && Texture->getSize().y == 16) {
			ObjectSprite->setScale(sf::Vector2f(4.0f, 4.0f));
		}
	}
}