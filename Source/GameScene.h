#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "MyObject.h"

class GameScene {
private:
	b2World* m_World = nullptr;
public:
	GameScene();
	~GameScene();

	bool IsSetup();

	void AddObject(MyObject NewObject);

	void Update(float fDeltaTime);
	void Render();
};