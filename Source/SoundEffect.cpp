// Precompiled Headers
#include "stdafx.h"

#include "SoundEffect.h"

SoundEffect::SoundEffect() {

}

SoundEffect::SoundEffect(sf::SoundBuffer* SoundBuffer) {
	m_Sound.setBuffer(*SoundBuffer);
	m_bIsLoaded = true;
	Play();
}

SoundEffect::~SoundEffect() {

}

void SoundEffect::SetBuffer(sf::SoundBuffer* SoundBuffer) {
	m_Sound.setBuffer(*SoundBuffer);
	m_bIsLoaded = true;
	Play();
}

void SoundEffect::Play() {
	if (m_bIsLoaded) {
		m_Sound.play();
	}
	
}

void SoundEffect::Pause() {
	if (m_bIsLoaded) {
		m_Sound.play();
	}
	
}

void SoundEffect::Stop() {
	if (m_bIsLoaded) {
		m_Sound.stop();
	}
}

void SoundEffect::SetRepeat() {
	if (m_bIsLoaded) {
		m_Sound.setLoop(true);
	}
}

void SoundEffect::SetNoRepeat() {
	if (m_bIsLoaded) {
		m_Sound.setLoop(false);
	}
}

bool SoundEffect::IsLoaded() {
	return m_bIsLoaded;
}

bool SoundEffect::IsStopped() {
	if (m_Sound.getStatus() == sf::SoundSource::Status::Stopped) {
		return true;
	}
	return false;
}