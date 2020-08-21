// Precompiled Headers
#include "stdafx.h"

#include "Wall.h"

Wall::Wall() {

}

Wall::Wall(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_StaticTexture = RM->GetTexture(strTextureName);
	m_PhysicsBody = PhysicsBody;

	m_StaticTexture.Fetch(&m_Sprite);
}

Wall::Wall(const Wall& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_StaticTexture.Fetch(&m_Sprite);
}

Wall::~Wall() {

}

void Wall::Update(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Wall::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		RenderWindow->draw(m_Sprite);
	}
}

void Wall::MoveDown(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Wall::MoveUp(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Wall::MoveLeft(float fDeltaTime) {
	if (m_iID != -1) {

	}
}

void Wall::MoveRight(float fDeltaTime) {
	if (m_iID != -1) {

	}
}