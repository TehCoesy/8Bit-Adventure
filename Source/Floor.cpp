// Precompiled Headers
#include "stdafx.h"

#include "Floor.h"

Floor::Floor() {

}

Floor::Floor(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_StaticTexture = RM->GetTexture(strTextureName);
	m_PhysicsBody = PhysicsBody;

	m_StaticTexture.Fetch(&m_Sprite);
}

Floor::Floor(const Floor& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_StaticTexture.Fetch(&m_Sprite);
}

Floor::~Floor() {

}

void Floor::Update(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Floor::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		RenderWindow->draw(m_Sprite);
	}
}

void Floor::MoveDown(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Floor::MoveUp(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Floor::MoveLeft(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Floor::MoveRight(float fDeltaTime) {
	if (m_iID != -1) {

	}
}