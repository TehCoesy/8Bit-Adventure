// Precompiled Headers
#include "stdafx.h"

#include "SoundEffect.h"

SoundEffect::SoundEffect() {

}

SoundEffect::SoundEffect(sf::SoundBuffer* SoundBuffer) {
	m_Sound.setBuffer(*SoundBuffer);
	Play();
}

SoundEffect::SoundEffect(const SoundEffect& cObject) {
	
}

SoundEffect::~SoundEffect() {

}

void SoundEffect::SetBuffer(sf::SoundBuffer* SoundBuffer) {
	m_Sound.setBuffer(*SoundBuffer);
	Play();
}

bool SoundEffect::IsDone() {
	if (m_Sound.getStatus() == sf::SoundSource::Status::Stopped) {
		return true;
	}
	else {
		return false;
	}
}

void SoundEffect::Play() {
	m_Sound.play();
}

void SoundEffect::Pause() {
	m_Sound.pause();
}

void SoundEffect::Stop() {
	m_Sound.stop();
}

void SoundEffect::ToggleRepeat() {
	m_Sound.setLoop(!m_Sound.getLoop());
}