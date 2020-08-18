// Precompiled Headers
#include "stdafx.h"

#include "Player.h"

#define iTICK 100

bool death = false;

Player::Player() {
	SetState(&Player::Spawn);
	Init();
}
/*
Player::Player(Vector3 pos, Vector3 scale, Vector3 rotation) : Player()
{
	
	//Update transform
	UpdatePosition(pos.x, pos.y, pos.z);
	UpdateRotation(rotation.x, rotation.y, rotation.z);
	UpdateScale(scale.x, scale.y, scale.z);

	Init();
}
*/
Player::~Player() {

}

void Player::Init() {};

void Player::UpdateHP() {};

void Player::SetColliable(bool state) {};

void Player::PlayAnimation(int key) {};

void Player::Spawn() {};

void Player::Walk() {};

void Player::Run() {};

void Player::GetHit() {};

void Player::Death() {};

void Player::CalculateVelocity() {};


void Player::CalculateAngle() {};

void Player::CheckCollision(MyObject* tempObj) {};

void Player::Update(float deltaTime) {};




