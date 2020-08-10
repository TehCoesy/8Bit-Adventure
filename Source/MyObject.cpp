// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

MyObject::MyObject() {
}

MyObject::~MyObject() {
}

void MyObject::CreateObject(sf::Texture Texture) {
	m_Sprite.setTexture(Texture);
}

void MyObject::Update(float fDeltaTime) {

}

void MyObject::Render() {

}