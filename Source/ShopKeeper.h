#pragma once

// Precompiled Headers
#include "stdafx.h"
#include "MyObject.h"
#include "Animation.h"
#include "Game.h"
#include <math.h>
using namespace std;

class ShopKeeper
{
public:
	ShopKeeper();
	//ShopKeeper(Vector3 pos, Vector3 scale, Vector3 rotation);
	~ShopKeeper();

	
	void SetState(void(ShopKeeper::* state)()) {
		activeState = state;
	}

	void SetCollidable(bool state);

	void Update(float deltaTime);
	void PlayAnimation(int key);
	void Spawn();
	void CheckCollision(MyObject* tempObj);
	void Init();
	void(ShopKeeper::* activeState)() = NULL;
	int activeAnimation = -1;
	vector<Animation*> animationList{};
};