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

		// Loading static Texturess
		int iTexturesCount = 0;
		iVal = fscanf(FileStream, "#TEXTURES: %d\n", &iTexturesCount);

		for (int i = 0; i < iTexturesCount; i++) {
			int iID = -1;
			char strBuffer1[100], strBuffer2[100];
			float fScaleX = TILE_SIZE, fScaleY = TILE_SIZE;

			iVal = fscanf(FileStream, "TEX ID %d %s %s %f %f\n", &iID, strBuffer1, strBuffer2, &fScaleX, &fScaleY); // TEX ID [iID] [strTextureName] [strFilePath]

			//printf("TEX ID %d %s %s\n", iID, strBuffer1, strBuffer2);

			if (iID != -1) {
				MyTexture NewTexture = LoadTexture(iID, std::string(strBuffer1), std::string(strBuffer2), fScaleX, fScaleY);
				m_aTextures.push_back(NewTexture);
			}
		}

		// Loading Animations
		int iAnimationsCount = 0;
		iVal = fscanf(FileStream, "#ANIMATIONS: %d\n", &iAnimationsCount);

		for (int i = 0; i < iAnimationsCount; i++) {
			int iID = -1;
			int iFrames = 0, iTimeSteps = 0;
			char strBuffer1[100], strBuffer2[100];

			iVal = fscanf(FileStream, "ANI ID %d NAME %s FRAMES %d TIMESTEP %d\n", &iID, strBuffer1, &iFrames, &iTimeSteps); // ANI ID [iID] NAME [cName] FRAMES[iFrames] TIMESTEP[iTimeStep]

			float fScaleX = TILE_SIZE, fScaleY = TILE_SIZE;
			std::vector<MyTexture> graFrames;
			
			for (int k = 0; k < iFrames; k++) {
				iVal = fscanf(FileStream, "%*d %s %f %f\n", strBuffer2, &fScaleX, &fScaleY);

				MyTexture NewFrame = LoadTexture(0, "Frame", std::string(strBuffer2), fScaleX, fScaleY);

				graFrames.push_back(NewFrame);
			}

			if (iID != -1) {
				Animation NewAnimation = LoadAnimation(iID, std::string(strBuffer1), iTimeSteps, graFrames);
				m_aAnimations.push_back(NewAnimation);
			}
		}

		// Close FileStream
		fclose(FileStream);
	}
	else {
		printf("(ResourceManager) Failed to open file @\"%s\"\n", strFilePath.c_str());
	}
}

MyTexture ResourceManager::LoadTexture(int iID, std::string strName, std::string strFilePath, float fScaleX, float fScaleY) {
	strFilePath = RESOURCESFOLDER + strFilePath;

	sf::Texture* Texture = new sf::Texture;
	if (!Texture->loadFromFile(strFilePath))
	{
		printf("(ResourceManager) Error loading texture! @%s", strFilePath.c_str());
		return MyTexture();
	}

	MyTexture NewTexture = MyTexture(iID, strName, Texture);

	NewTexture.SetScale(fScaleX, fScaleY);

	return NewTexture;
}

Animation ResourceManager::LoadAnimation(int iID, std::string strName, int iTimeSteps, std::vector<MyTexture> graFrames) {
	Animation NewAnimation = Animation(iID, strName, iTimeSteps, graFrames);
	return NewAnimation;
}

MyTexture ResourceManager::GetTexture(std::string strName) {
	for (unsigned int i = 0; i < m_aTextures.size(); i++) {
		if (*m_aTextures.at(i).GetName() == strName) {
			return m_aTextures.at(i);
		}
	}
	return MyTexture();
}

Animation ResourceManager::GetAnimation(std::string strName) {
	for (unsigned int i = 0; i < m_aAnimations.size(); i++) {
		if (*m_aAnimations.at(i).GetName() == strName) {
			return m_aAnimations.at(i);
		}
	}
	return Animation();
}