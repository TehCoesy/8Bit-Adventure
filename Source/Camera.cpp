// Precompiled Headers
#include "stdafx.h"

#include "Camera.h"

Camera::Camera() {

}

Camera::~Camera() {

}

b2Vec2 Camera::GetCameraVector() {
	return b2Vec2(m_fCameraCenter.x - m_fCameraWorldPosition.x, m_fCameraCenter.y - m_fCameraWorldPosition.y);
}

b2Vec2 Camera::GetCameraCenter() {
	return m_fCameraCenter;
}

void Camera::SetCameraPosition(float fPosX, float fPosY) {
	m_fCameraWorldPosition.x = fPosX; m_fCameraWorldPosition.y = fPosY;
}