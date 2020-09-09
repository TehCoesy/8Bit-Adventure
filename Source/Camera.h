#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "Singleton.h"

class Camera : public Singleton<Camera> {
private:
	b2Vec2 m_fCameraCenter = b2Vec2(WINDOW_W / 2 + TILE_SIZE / 2, WINDOW_H / 2 + TILE_SIZE / 2);
	b2Vec2 m_fCameraWorldPosition = b2Vec2(0.0f, 0.0f);
public:
	Camera();
	~Camera();
	   
	b2Vec2 GetCameraVector();
	b2Vec2 GetCameraCenter();

	void SetCameraPosition(float fPosX, float fPosY);
};