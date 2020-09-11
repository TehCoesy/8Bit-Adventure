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

	m_fDesiredX = cMyTexture.m_fDesiredX;
	m_fDesiredY = cMyTexture.m_fDesiredY;
}

MyTexture::~MyTexture() {
}

int* MyTexture::GetID() {
	return &m_iID;
}

std::string* MyTexture::GetName() {
	return &m_strName;
}

void MyTexture::SetRepeated(bool a)
{
	m_Texture->setRepeated(a);
}

void MyTexture::SetScale(float fScaleX, float fScaleY) {
	m_fDesiredX = fScaleX;
	m_fDesiredY = fScaleY;
}

void MyTexture::Fetch(sf::Sprite* ObjectSprite) {
	if (m_iID != -1) {
		ObjectSprite->setTexture(*m_Texture);
	}
}