// Precompiled Headers
#include "stdafx.h"

#include "Player.h"

#define iTICK 100

bool death = false;

Player::Player() {
	m_fVelocity = 3.0f;
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

void Player::Spawn() {};

void Player::Walk(int iDirect) {
	switch (iDirect)
	{
	case 0://up
		m_Sprite.move(0.0f, -m_fVelocity);
		break;
	case 1://down
		m_Sprite.move(0.0f, m_fVelocity);
		break;
	case 2://left
		m_Sprite.move(-m_fVelocity, 0.0f);
		break;
	case 3://right
		m_Sprite.move(m_fVelocity, 0.0f);
		break;
	default:
		break;
	}
	m_iDirection = iDirect;
};

void Player::Run() {};

void Player::GetHit() {};

void Player::Death() {};

void Player::CalculateVelocity() {};

void Player::CalculateAngle() {};

void Player::CheckCollision(MyObject* tempObj) {};

void Player::Update(float deltaTime) {
};

sf::Sprite Player::GetSprite() {
	return m_Sprite;
}