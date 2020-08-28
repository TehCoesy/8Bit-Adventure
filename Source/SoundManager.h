#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Audio.hpp"

// Local
#include "Singleton.h"

class SoundManager : public Singleton<SoundManager> {
private:
	std::vector<sf::SoundBuffer> m_SoundBuffers;
public:
	void LoadFromFile(std::string strFilePath);
};