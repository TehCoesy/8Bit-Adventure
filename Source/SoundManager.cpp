// Precompiled Headers
#include "stdafx.h"

#include "SoundManager.h"

SoundManager::SoundManager() {
	m_Music = new Music();
}

SoundManager::~SoundManager() {

}

void SoundManager::InitWithFile(std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		int iVal;
		int iSoundEffectCount, iMusicCount;

		iVal = fscanf(FileStream, "#SOUNDEFFECTS: %d\n", &iSoundEffectCount);

		for (int i = 0; i < iSoundEffectCount; i++) {
			char strBuffer1[100], strBuffer2[100];

			iVal = fscanf(FileStream, "%s %s\n", strBuffer1, strBuffer2);

			sf::SoundBuffer* NewSoundBuffer = new sf::SoundBuffer();

			if (NewSoundBuffer->loadFromFile(std::string(RESOURCESFOLDER + std::string(strBuffer2)))) {
				m_strSoundEffects.push_back(std::string(strBuffer1));
				m_SoundBuffers.push_back(NewSoundBuffer);
			}
			else {
				printf("Unable to load SoundBuffer");
			}
		}

		iVal = fscanf(FileStream, "#MUSICS: %d\n", &iMusicCount);

		for (int i = 0; i < iMusicCount; i++) {
			char strBuffer1[100], strBuffer2[100];

			iVal = fscanf(FileStream, "%s %s\n", strBuffer1, strBuffer2);

			m_strMusics.push_back(std::string(strBuffer1));
			m_strMusicFilePaths.push_back(std::string(strBuffer2));
		}

		fclose(FileStream);
	}
}

void SoundManager::PlayEffectByName(std::string strSoundEffect) {
	for (int i = 0; i < m_strSoundEffects.size(); i++) {
		if (m_strSoundEffects.at(i) == strSoundEffect) {
			SoundEffect* NewSoundEffect = new SoundEffect(m_SoundBuffers.at(i));
			m_SoundEffects.push_back(NewSoundEffect);
			return;
		}
	}
	printf("No such SoundEffect found.");
}

void SoundManager::PlayMusicByName(std::string strMusic) {
	for (int i = 0; i < m_strMusics.size(); i++) {
		if (m_strMusics.at(i) == strMusic) {
			m_Music->NewTrack(m_strMusicFilePaths.at(i));
			return;
		}
	}
	printf("No such Music track found.");
}

void SoundManager::Clean() {
	for (int i = 0; i < m_SoundEffects.size(); i++) {
		SoundEffect* soundEffect = m_SoundEffects.at(i);
		if (soundEffect->IsStopped() && !soundEffect->IsRepeating()) {
			m_SoundEffects.erase(m_SoundEffects.begin() + i);
			delete soundEffect;
		}
	}
}