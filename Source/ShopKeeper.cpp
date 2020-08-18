#include "stdafx.h"
#include "ShopKeeper.h"
#include "Control.h"


ShopKeeper::ShopKeeper()
{
	SetState(&ShopKeeper::Spawn);
	Init();
}




ShopKeeper::~ShopKeeper()
{
}


void ShopKeeper::Init() {};


void ShopKeeper::PlayAnimation(int key) {};

void ShopKeeper::Spawn() {};


void ShopKeeper::CheckCollision(MyObject* tempObj)
{
}


void ShopKeeper::SetCollidable(bool state) {};


void ShopKeeper::Update(float deltaTime) {};

