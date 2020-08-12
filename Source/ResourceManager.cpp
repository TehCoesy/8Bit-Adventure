// Precompiled Headers
#include "stdafx.h"

#include "ResourceManager.h"

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {

}

void ResourceManager::InitWithFile(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		// Close FileStream
		fclose(FileStream);
	}
}

void ResourceManager::LoadTexture(std::string strFilePath) {
	sf::Texture Texture;
	if (!Texture.loadFromFile(strFilePath)) 
	{
		printf("(ResourceManager) Error loading texture! @%s", strFilePath.c_str());
		return;
	}
	m_aTextures.push_back(Texture);
}

void ResourceManager::LoadSoundBuffers(std::string strFilePath) {
	sf::SoundBuffer SoundBuffer;
	if (!SoundBuffer.loadFromFile(strFilePath)) // .wav Files
	{
		printf("(ResourceManager) Error loading sound! @%s", strFilePath.c_str());
		return;
	}
	m_aSoundBuffers.push_back(SoundBuffer);
}