#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Audio.hpp"

class Music {
private:
	sf::Music m_Music;

	bool m_bIsLoaded;
public:
	Music();
	Music(std::string strFilePath);
	~Music();

	void NewTrack(std::string strFilePath);

	void Play();
	void Pause();
	void Stop();

	void SetRepeat();
	void SetNoRepeat();

	bool IsLoaded();
	bool IsStopped();
};