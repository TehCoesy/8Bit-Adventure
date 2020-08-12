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
		int iVal;

		// Loading Animations

		// Loading (Static) Textures
		int iTexturesCount = 0;
		iVal = fscanf(FileStream, "#TEXTURES: %d\n", &iTexturesCount);

		for (int i = 0; i < iTexturesCount; i++) {
			int iID = -1;
			char strBuffer1[100], strBuffer2[100];
			iVal = fscanf(FileStream, "TEX ID %d %s %s\n", &iID, strBuffer1, strBuffer2); // TEX ID [iID] [strTextureName] [strFilePath]

			//printf("TEX ID %d %s %s\n", iID, strBuffer1, strBuffer2);

			if (iID != -1) {
				LoadTexture(iID, std::string(strBuffer1), std::string(strBuffer2));
			}
		}

		// Loading Sounds

		// Close FileStream
		fclose(FileStream);
	}
	else {
		printf("(ResourceManager) Failed to open file @\"%s\"\n", strFilePath.c_str());
	}
}

void ResourceManager::LoadTexture(int iID, std::string strName, std::string strFilePath) {
	strFilePath = RESOURCESFOLDER + strFilePath;

	sf::Texture Texture;
	if (!Texture.loadFromFile(strFilePath)) 
	{
		printf("(ResourceManager) Error loading texture! @%s", strFilePath.c_str());
		return;
	}
	MyTexture NewTexture(iID, strName, Texture);
	m_aTextures.push_back(NewTexture);
}

void ResourceManager::LoadAnimation() {

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