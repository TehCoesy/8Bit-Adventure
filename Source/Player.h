#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"
#include "Animation.h"

using namespace std;
class Player : public MyObject{
public:
	Player();
	//Player(Vector3 pos, Vector3 scale, Vector3 rotation);
	~Player();
	void SetState(void(Player::*state)()) {
		activeState = state;
	}
	void Update(float deltaTime);

	void PlayAnimation(int key);

	void Spawn();

	void Walk();

	void Run();

	void GetHit();

	void Death();

	void CalculateVelocity();

	void CalculateAngle();

	void CheckCollision(MyObject* tempObj);

	void Init();

	void UpdateHP();

	void(Player::* activeState)() = NULL;

	int activeAnimation = -1;

	vector<Animation*>animationList{};

	int iTick = 0;

	float angle;

	float velX, velY;

	bool immune = false;

	void SetColliable(bool state);


private:
};