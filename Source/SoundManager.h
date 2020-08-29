#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Audio.hpp"

// Local
#include "SoundEffect.h"
#include "Music.h"
#include "Singleton.h"

class SoundManager : public Singleton<SoundManager> {
private:
	std::vector<sf::SoundBuffer*> m_SoundBuffers;
	std::vector<SoundEffect*> m_SoundEffects;
	std::vector<std::string> m_SoundEffectsName;
	std::vector<std::string> m_Musics;
	Music* m_Music;
public:
	SoundManager();
	~SoundManager();

	void LoadFromFile(std::string strFilePath);

	void PlayEffectByName(std::string strSoundEffect);
	void PlayMusic(std::string strFilePath);
};