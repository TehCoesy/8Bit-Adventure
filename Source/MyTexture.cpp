// Precompiled Headers
#include "stdafx.h"

#include "MyTexture.h"

MyTexture::MyTexture() {
	m_Texture = new sf::Texture();
}

MyTexture::MyTexture(int iID, std::string strName, sf::Texture* Texture) {
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

void MyTexture::Fetch(sf::Sprite* ObjectSprite) {
	if (m_iID != -1) {
		ObjectSprite->setTexture(*m_Texture);

		if (m_Texture->getSize().x == 32 && m_Texture->getSize().y == 32) {
			ObjectSprite->setScale(sf::Vector2f(2.0f, 2.0f));
		}
		else if (m_Texture->getSize().x == 16 && m_Texture->getSize().y == 16) {
			ObjectSprite->setScale(sf::Vector2f(4.0f, 4.0f));
		}
	}
}