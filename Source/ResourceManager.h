#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// Local
#include "Singleton.h"
#include "Animation.h"
#include "MyTexture.h"

// Macros
#define ResourcesFolder "./Resources/"

class ResourceManager : public Singleton<ResourceManager> {
private:
	std::vector<MyTexture> m_aTextures;
	std::vector<Animation> m_aAnimations;
	std::vector<sf::SoundBuffer> m_aSoundBuffers;

	void LoadTexture(int iID, std::string strName, std::string strFilePath);
	void LoadAnimation(int iID, std::vector<int> aIDTexture, std::string strAnimationName, int iFrames, int iTimeSteps, std::vector<std::string> strFilePath);
	void LoadSoundBuffers(std::string strFilePath);

	int m_iTexturesCount = 0, m_iAnimationsCount = 0, m_iSoundsCount = 0;
public:
	ResourceManager();
	~ResourceManager();

	void InitWithFile(std::string strFilePath);
	std::vector<Animation> GetAnimationList();

	MyTexture GetTexture(int iID);
};