#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "SFML/Graphics.hpp"

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

	MyTexture LoadTexture(int iID, std::string strName, std::string strFilePath, float fScaleX, float fScaleY);
	Animation LoadAnimation(int iID, std::string strName, int iTimeSteps, std::vector<MyTexture> graFrames);
public:
	ResourceManager();
	~ResourceManager();

	void InitWithFile(std::string strFilePath);

	MyTexture GetTexture(std::string strName);
	Animation GetAnimation(std::string strName);
};