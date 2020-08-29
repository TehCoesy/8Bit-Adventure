// Precompiled Headers
#include "stdafx.h"

#include "Music.h"

Music::Music() {

}

Music::Music(std::string strFilePath) {
	m_strFilePath = RESOURCESFOLDER + strFilePath;
	if (m_Music.openFromFile(m_strFilePath)) {
		m_bIsValid = true;
		ToggleRepeat();
		Play();
	}
	else {
		printf("Failed to open music file @%s", m_strFilePath.c_str());
	}
}

Music::Music(const Music& cObject) {
	m_strFilePath = cObject.m_strFilePath;
	if (m_Music.openFromFile(m_strFilePath)) {
		m_bIsValid = true;
		ToggleRepeat();
		Play();
	}
	else {
		printf("Failed to open music file @%s", m_strFilePath.c_str());
	}
}

Music::~Music() {

}

void Music::Play() {
	if (m_bIsValid) {
		m_Music.play();
	}
	
}

void Music::Pause() {
	if (m_bIsValid) {
		m_Music.pause();
	}
	
}

void Music::Stop() {
	if (m_bIsValid) {
		m_Music.stop();
	}
}

void Music::ToggleRepeat() {
	if (m_bIsValid) {
		m_Music.setLoop(!m_Music.getLoop());
	}
}

bool Music::IsValid() {
	return m_bIsValid;
}