#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class EnemySpawner : public MyObject {
private:
public:
	EnemySpawner();
	EnemySpawner(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody);
	EnemySpawner(const EnemySpawner& cObject);
	~EnemySpawner();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};