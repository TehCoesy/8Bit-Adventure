#pragma once

#include "stdafx.h"
#include "MyObject.h"
#include "Animation.h"
#include "Game.h"
#include <math.h>

using namespace std;
class Boss :
	public MyObject
{
public:
	Boss();
	//Boss(Vector3 pos, Vector3 scale, Vector3 rotation);
	~Boss();

	void SetState(void(Boss::* state)()) {
		activeState = state;
	}
	float x, y, velX, velY, distance;

	void PlayAnimation(int key);
	void Spawn();

	void WalkLeft();
	void WalkRight();
	void Death();
	void CalculateVelocity(float mX, float mY);
	void DoStuff();
	void Update(float deltaTime);
	void CheckCollision(MyObject* tempObj);
	void Init();
	void(Boss::* activeState)() = NULL;
	int activeAnimation = -1;
	vector<Animation*> animeList{};
};