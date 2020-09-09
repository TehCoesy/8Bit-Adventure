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
	std::vector<SoundEffect*> m_SoundEffects;
	std::vector<std::string> m_strSoundEffects;
	std::vector<sf::SoundBuffer*> m_SoundBuffers;

	Music* m_Music;
	std::vector<std::string> m_strMusics;
	std::vector<std::string> m_strMusicFilePaths;
public:
	SoundManager();
	~SoundManager();

	void InitWithFile(std::string strFilePath);

	void PlayEffectByName(std::string strSoundEffect);
	void PlayMusicByName(std::string strMusic);
};