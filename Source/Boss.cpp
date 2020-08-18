#include "stdafx.h"
#include "Boss.h"

Boss::Boss() {
	SetState(&Boss::Spawn);
	Init();
};
Boss::~Boss() {};

void Boss::Init() {};

void Boss::PlayAnimation(int key) {};

void Boss::Spawn() {};


void Boss::CheckCollision(MyObject* tempObj)
{
}



void Boss::Update(float deltaTime) {};

void Boss::WalkLeft()
{
	//State execution
	//PlayAnimation(0);
}

void Boss::WalkRight()
{
	//State execution
	//PlayAnimation(0);
}

void Boss::Death() {};

void Boss::CalculateVelocity(float mX, float mY) {};

void DoStuff() {};
