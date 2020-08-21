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

		// Loading static Textures
		iVal = fscanf(FileStream, "#TEXTURES: %d\n", &m_iTexturesCount);

		for (int i = 0; i < m_iTexturesCount; i++) {
			int iID = -1;
			char strBuffer1[100], strBuffer2[100];
			iVal = fscanf(FileStream, "TEX ID %d %s %s\n", &iID, strBuffer1, strBuffer2); // TEX ID [iID] [strTextureName] [strFilePath]

			//printf("TEX ID %d %s %s\n", iID, strBuffer1, strBuffer2);

			if (iID != -1) {
				LoadTexture(iID, std::string(strBuffer1), std::string(strBuffer2));
			}
		}

		// Loading Animations
		iVal = fscanf(FileStream, "#ANIMATIONS: %d\n", &m_iAnimationsCount);

		for (int i = 0; i < m_iAnimationsCount; i++) {
			int iID = -1;
			int iFrames = 0, iTimeSteps = 0;
			char strBuffer1[100], strBuffer2[100];
			iVal = fscanf(FileStream, "ANI ID %d NAME %s FRAMES %d TIMESTEP %d\n", &iID, strBuffer1, &iFrames, &iTimeSteps); // ANI ID [iID] NAME [cName] FRAMES[iFrames] TIMESTEP[iTimeStep]

			std::vector<std::string> strFilePaths;

			for (int k = 0; k < iFrames; k++) {
				iVal = fscanf(FileStream, "%*d %s\n", strBuffer2);

				strFilePaths.push_back(std::string(strBuffer2));
			}

			//printf("ANI ID %d FRAMES %d TIMESTEP %d\n", iID, iFrames, iTimeSteps);

			if (iID != -1) {
				LoadAnimation(iID, std::string(strBuffer1), iTimeSteps, strFilePaths);
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

	sf::Texture* Texture = new sf::Texture;
	if (!Texture->loadFromFile(strFilePath))
	{
		printf("(ResourceManager) Error loading texture! @%s", strFilePath.c_str());
		return;
	}
	MyTexture NewTexture(iID, strName, Texture);
	m_aTextures.push_back(NewTexture);
}

void ResourceManager::LoadAnimation(int iID, std::string strName, int iTimeSteps, std::vector<std::string> strFilePaths) {
	std::vector<sf::Texture*> AnimationFrames;

	for (int i = 0; i < strFilePaths.size(); i++)
	{
		std::string strFilePath = RESOURCESFOLDER + strFilePaths.at(i);

		sf::Texture* Texture = new sf::Texture;

		if (!Texture->loadFromFile(strFilePath))
		{
			printf("(ResourceManager) Error loading texture! @%s", strFilePath.c_str());
			return;
		}

		AnimationFrames.push_back(Texture);
	}

	Animation NewAnimation(iID, strName, iTimeSteps, AnimationFrames);
	m_aAnimations.push_back(NewAnimation);
}

void ResourceManager::LoadSoundBuffers(std::string strFilePath) {

}

MyTexture ResourceManager::GetTexture(std::string strName) {
	for (int i = 0; i < m_aTextures.size(); i++) {
		if (*m_aTextures.at(i).GetName() == strName) {
			return m_aTextures.at(i);
		}
	}
	return MyTexture();
}

Animation ResourceManager::GetAnimation(std::string strName) {
	for (int i = 0; i < m_aAnimations.size(); i++) {
		if (*m_aAnimations.at(i).GetName() == strName) {
			return m_aAnimations.at(i);
		}
	}
	return Animation();
}