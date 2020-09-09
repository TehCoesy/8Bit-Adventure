// Precompiled Headers
#include "stdafx.h"

#include "Music.h"

Music::Music() {

}

Music::Music(std::string strFilePath) {
	strFilePath = RESOURCESFOLDER + strFilePath;
	if (m_Music.openFromFile(strFilePath)) {
		m_bIsLoaded = true;
		SetRepeat();
		Play();
	}
	else {
		printf("(Music) Failed to open music file @%s", strFilePath.c_str());
	}
}

Music::~Music() {

}

void Music::NewTrack(std::string strFilePath) {
	strFilePath = RESOURCESFOLDER + strFilePath;
	if (m_Music.openFromFile(strFilePath)) {
		m_bIsLoaded = true;
		SetRepeat();
		Play();
	}
	else {
		printf("(Music) Failed to open music file @%s", strFilePath.c_str());
	}
}

void Music::Play() {
	if (m_bIsLoaded) {
		m_Music.play();
	}
	
}

void Music::Pause() {
	if (m_bIsLoaded) {
		m_Music.pause();
	}
	
}

void Music::Stop() {
	if (m_bIsLoaded) {
		m_Music.stop();
	}
}

void Music::SetRepeat() {
	if (m_bIsLoaded) {
		m_Music.setLoop(true);
	}
}

void Music::SetNoRepeat() {
	if (m_bIsLoaded) {
		m_Music.setLoop(false);
	}
}

bool Music::IsLoaded() {
	return m_bIsLoaded;
}

bool Music::IsStopped() {
	if (m_Music.getStatus() == sf::SoundSource::Status::Stopped) {
		return true;
	}
	return false;
}