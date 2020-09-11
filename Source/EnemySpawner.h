#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "SpriteObject.h"

class EnemySpawner : public SpriteObject {
private:
	EnemySpawner(EnemySpawner const&) = delete;
	EnemySpawner& operator=(EnemySpawner const&) = delete;
public:
	EnemySpawner();
	EnemySpawner(int iID, std::string strName, std::string strTextureName, b2Body* PhysicsBody);
	~EnemySpawner();

	void Update(float fDeltaTime);
	void Render(sf::RenderWindow* RenderWindow);
};