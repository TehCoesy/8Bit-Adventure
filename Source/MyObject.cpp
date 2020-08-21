// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

MyObject::MyObject() {
}

MyObject::~MyObject() {
}

int* MyObject::GetID() {
	return &m_iID;
}

std::string* MyObject::GetName() {
	return &m_strName;
}

float* MyObject::GetHealth() {
	return &m_fHealth;
}

float* MyObject::GetVel() {
	return &m_fVelocity;
}

void MyObject::Update(float fDeltaTime) {

}

void MyObject::Render(sf::RenderWindow* MainWindow) {
}

void MyObject::NewAnimation(std::string strName) {
	m_Animation = RM->GetAnimation(strName);
}

void MyObject::NewTexture(std::string strName) {
	m_StaticTexture = RM->GetTexture(strName);
}

void MyObject::MoveDown(float fDeltaTime) {

}

void MyObject::MoveUp(float fDeltaTime) {

}

void MyObject::MoveLeft(float fDeltaTime) {

}

void MyObject::MoveRight(float fDeltaTime) {

}