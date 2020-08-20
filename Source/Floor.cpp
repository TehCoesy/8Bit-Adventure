// Precompiled Headers
#include "stdafx.h"

#include "Floor.h"

Floor::Floor() {

}

Floor::Floor(int iID, std::string strName, MyTexture NewTexture, b2Body* PhysicsBody) {
	m_iID = iID;
	m_strName = strName;

	m_StaticTexture = NewTexture;
	m_PhysicsBody = PhysicsBody;

	m_Sprite.setTexture(*m_StaticTexture.GetTexture());
}

Floor::Floor(const Floor& cObject) {
	m_iID = cObject.m_iID;
	m_strName = cObject.m_strName;

	m_StaticTexture = cObject.m_StaticTexture;
	m_PhysicsBody = cObject.m_PhysicsBody;

	m_Sprite.setTexture(*m_StaticTexture.GetTexture());
}

Floor::~Floor() {

}