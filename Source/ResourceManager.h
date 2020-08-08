#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// Local
#include "Singleton.h"

// Macros
#define ResourcesFolder "./Resources/"

class ResourceManager : public Singleton<ResourceManager> {
private:
	std::vector<sf::Texture> m_aTextures;
	std::vector<sf::SoundBuffer> m_aSoundBuffers;

	void LoadTexture(std::string strFilePath);
	void LoadSoundBuffers(std::string strFilePath);
public:
	void Init();
};