#pragma once
#include "stdafx.h"
#include "Singleton.h"
#include "Enemy.h"

class Normal_Enemy : public Singleton <Normal_Enemy> {
public:
	Normal_Enemy();
	~Normal_Enemy();
	void Interaction(Enemy* Enemy, float fPlayerPosX, float fPlayerPosY,float fDeltaTime);
	
};