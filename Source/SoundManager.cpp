// Precompiled Headers
#include "stdafx.h"

#include "SoundManager.h"

SoundManager::SoundManager() {

}

SoundManager::~SoundManager() {

}

void SoundManager::LoadFromFile(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;
		int iSoundEffectCount, iMusicCount;

		iVal = fscanf(FileStream, "#SOUNDEFFECTS: %d\n", &iSoundEffectCount);

		for (int i = 0; i < iSoundEffectCount; i++) {
			char strBuffer1[100], strBuffer2[100];

			iVal = fscanf(FileStream, "SB %s %s\n", strBuffer1, strBuffer2);

			sf::SoundBuffer* NewSoundBuffer = new sf::SoundBuffer();
			
			std::string strSoundEffectFilePath = RESOURCESFOLDER + std::string(strBuffer2);

			if (NewSoundBuffer->loadFromFile(std::string(strSoundEffectFilePath))) {
				m_SoundEffectsName.push_back(std::string(strBuffer1));
				m_SoundBuffers.push_back(NewSoundBuffer);
			}
			else {
				printf("Unable to load SoundBuffer");
			}
		}

		iVal = fscanf(FileStream, "#MUSICS: %d\n", &iMusicCount);

		for (int i = 0; i < iMusicCount; i++) {
			char strBuffer1[100], strBuffer2[100];

			iVal = fscanf(FileStream, "MUSIC %s %s\n", strBuffer1, strBuffer2);

			m_Musics.push_back(std::string(strBuffer1));
		}

		fclose(FileStream);
	}
}

void SoundManager::PlayEffectByName(std::string strSoundEffect) {
	for (int i = 0; i < m_SoundEffectsName.size(); i++) {
		if (m_SoundEffectsName.at(i) == strSoundEffect) {
			SoundEffect* NewSE = new SoundEffect(m_SoundBuffers.at(i));
			m_SoundEffects.push_back(NewSE);
			return;
		}
	}
	printf("No such SoundEffect found.");
}

void SoundManager::PlayMusic(std::string strFilePath) {
	m_Music = new Music(strFilePath);
}