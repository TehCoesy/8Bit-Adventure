// Precompiled Headers
#include "stdafx.h"

#include "Animation.h"

Animation::Animation() {

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

void Animation::Update(float fDeltaTime) {

}

void Animation::Fetch(sf::Sprite* ObjectSprite) {

}