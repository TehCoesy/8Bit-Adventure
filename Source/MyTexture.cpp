// Precompiled Headers
#include "stdafx.h"

#include "MyTexture.h"

MyTexture::MyTexture() {
}

MyTexture::MyTexture(int iID, std::string strName, sf::Texture Texture) {
	m_iID = iID;
	m_strName = strName;
	m_Texture = Texture;
}

MyTexture::MyTexture(const MyTexture& cMyTexture) {
	m_iID = cMyTexture.m_iID;
	m_strName = cMyTexture.m_strName;
	m_Texture = cMyTexture.m_Texture;
}

MyTexture::~MyTexture() {
}

int* MyTexture::GetID() {
	return &m_iID;
}

std::string* MyTexture::GetName() {
	return &m_strName;
}

sf::Texture* MyTexture::GetTexture() {
	return &m_Texture;
}

void MyTexture::Fetch(sf::Sprite* ObjectSprite) {
	if (m_iID != -1) {
		ObjectSprite->setTexture(m_Texture);
	}
}