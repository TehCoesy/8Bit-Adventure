// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

MyObject::MyObject() {
	m_PhysicsBody = nullptr;
}

MyObject::~MyObject() {
}

void MyObject::DestroyBody() {
	m_PhysicsBody->GetWorld()->DestroyBody(m_PhysicsBody);
}

int* MyObject::GetID() {
	return &m_iID;
}

std::string* MyObject::GetName() {
	return &m_strName;
}

ObjectState MyObject::GetObjectState() {
	return m_ObjectState;
}

ObjectType MyObject::GetObjectType() {
	return m_ObjectType;
}

b2Body* MyObject::GetPhysicsBody() {
	return m_PhysicsBody;
}

b2Vec2* MyObject::GetSizeP() {
	return &m_fSizeP;
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

float MyObject::Radian2Degree(float fRadian) {
	return fRadian * (180.0f / b2_pi);
}

float MyObject::Degree2Radian(float fDegree) {
	return fDegree * (b2_pi / 180.0f);
}