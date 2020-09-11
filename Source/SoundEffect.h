#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Audio.hpp"

class SoundEffect {
private:
	sf::Sound m_Sound;

	bool m_bIsLoaded = false;
public:
	SoundEffect();
	SoundEffect(sf::SoundBuffer* SoundBuffer);
	~SoundEffect();
	
	void SetBuffer(sf::SoundBuffer* SoundBuffer);

	void Play();
	void Pause();
	void Stop();

	void SetRepeat();
	void SetNoRepeat();

	bool IsRepeating();
	bool IsLoaded();
	bool IsStopped();
};