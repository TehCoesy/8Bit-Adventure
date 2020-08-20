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
#pragma region Loading (Static) Textures

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
#pragma endregion

#pragma region Loading Animations

		int iAnimCounts = 0;
		iVal = fscanf(FileStream, "#ANIMATIONS: %d\n", &iAnimCounts);

		for (int i = 0; i < iAnimCounts; i++) {
			int iID = -1, iFrames, iTimeSteps;
			int iIDTexture;
			std::vector<int> aIDTexture;
			char cName[100];
			iVal = fscanf(FileStream, "ANI ID %d NAME %s FRAMES %d TIMESTEP %d\n", &iID, cName, &iFrames, &iTimeSteps); // ANI ID [iID] NAME [cName] FRAMES[iFrames] TIMESTEP[iTimeStep]

			std::vector<std::string> aStrFilePath;
			for (int j = 0; j < iFrames; j++) {
				char strBuffer[100];

				iVal = fscanf(FileStream, "%d %s\n", &iIDTexture, strBuffer);
				//printf("%s\n", strBuffer);
				aIDTexture.push_back(iIDTexture);
				aStrFilePath.push_back(std::string(strBuffer));
			}

			//printf("ANI ID %d FRAMES %d TIMESTEP %d\n", iID, iFrames, iTimeSteps);

			if (iID != -1) {
				LoadAnimation(iID, aIDTexture, cName, iFrames, iTimeSteps, aStrFilePath);
			}
		}
#pragma endregion

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

void ResourceManager::LoadAnimation(int iID, std::vector<int> aIDTexture, std::string strAnimationName, int iFrames, int iTimeSteps, std::vector<std::string> aStrFilePath) {
	//load animation frames
	std::vector<MyTexture> aAnimationFrames;
	for (int i = 0; i < aStrFilePath.size(); i++)
	{
		aStrFilePath.at(i) = RESOURCESFOLDER + aStrFilePath.at(i);

		sf::Texture* Texture = new sf::Texture;

		if (!Texture->loadFromFile(aStrFilePath.at(i)))
		{
			printf("(ResourceManager) Error loading texture! @%s", aStrFilePath.at(i).c_str());
			return;
		}

		MyTexture NewTexture(aIDTexture.at(i), "", Texture);
		aAnimationFrames.push_back(NewTexture);
	}

	Animation NewAnimation(iID, iFrames, iTimeSteps, strAnimationName, aAnimationFrames);
	m_aAnimations.push_back(NewAnimation);
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

std::vector<Animation> ResourceManager::GetAnimationList() {
	return m_aAnimations;
}

MyTexture ResourceManager::GetTexture(int iID) {
	for (int i = 0; i < m_aTextures.size(); i++) {
		if (m_aTextures.at(i).GetID() == iID) {
			return m_aTextures.at(i);
		}
	}
	return MyTexture();
}