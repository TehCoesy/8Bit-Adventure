#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Audio.hpp"

class SoundEffect {
private:
	sf::Sound m_Sound;
public:
	SoundEffect();
	SoundEffect(sf::SoundBuffer* SoundBuffer);
	SoundEffect(const SoundEffect& cObject);
	~SoundEffect();
	
	void SetBuffer(sf::SoundBuffer* SoundBuffer);

	bool IsDone();

	void Play();
	void Pause();
	void Stop();

	void ToggleRepeat();
};