// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

MyObject::MyObject() {
	m_PhysicsBody = nullptr;
}

MyObject::~MyObject() {
}

int* MyObject::GetID() {
	return &m_iID;
}

std::string* MyObject::GetName() {
	return &m_strName;
}

ObjectType MyObject::GetObjectType() {
	return m_ObjectType;
}

b2Body* MyObject::GetPhysicsBody() {
	return m_PhysicsBody;
}

bool MyObject::IsActive() {
	return m_bIsActive;
}

void MyObject::ToggleActive() {
	m_bIsActive = !m_bIsActive;
}

void MyObject::Update(float fDeltaTime) {
}

void MyObject::Render(sf::RenderWindow* MainWindow) {
}