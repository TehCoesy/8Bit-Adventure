#pragma once
#include"stdafx.h"
#include"Enemy.h"
#include"Singleton.h"
class Normal_Enemy :public Singleton<Normal_Enemy> {
public:
	Normal_Enemy();
	~Normal_Enemy();
	void Interaction(Enemy* m_Enermy, float fPlayerPosX, float fPlayerPosY, float fDeltaTime);
};