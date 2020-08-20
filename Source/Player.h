#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"
#include "ResourceManager.h"
using namespace std;
class Player : public MyObject {
public:
	Player();
	//Player(Vector3 pos, Vector3 scale, Vector3 rotation);
	~Player();
	void SetState(void(Player::* state)()) {
		activeState = state;
	}
	void Update(float deltaTime);

	void Spawn();

	void Walk(int iDirect);

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
	
	int iTick = 0;

	float angle;

	

	bool immune = false;

	void SetColliable(bool state);

	sf::Sprite GetSprite();
private:
};