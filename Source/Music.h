#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Audio.hpp"

class Music {
private:
	std::string m_strFilePath;
	sf::Music m_Music;

	bool m_bIsValid;
public:
	Music();
	Music(std::string strFilePath);
	Music(const Music& cObject);
	~Music();

	void Play();
	void Pause();
	void Stop();
	void ToggleRepeat();

	bool IsValid();
};