// Precompiled Headers
#include "stdafx.h"

#include "Music.h"

Music::Music(std::string strFilePath) {
	strFilePath = RESOURCESFOLDER + strFilePath;
	if (m_Music.openFromFile(strFilePath)) {
		m_bIsValid = true;
		Play();
	}
	else {
		printf("Failed to open music file @%s", strFilePath.c_str());
	}
}

Music::Music(const Music& cObject) {

}

Music::~Music() {

}

void Music::Play() {
	m_Music.play();
}

void Music::Pause() {
	m_Music.pause();
}

void Music::Stop() {
	m_Music.stop();
}

void Music::ToggleRepeat() {
	m_bRepeat = !m_bRepeat;
}

bool Music::IsValid() {
	return m_bIsValid;
}