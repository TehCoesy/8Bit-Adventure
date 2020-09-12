#include"stdafx.h"
#include"Normal_Enemy.h"

Normal_Enemy::Normal_Enemy() {};
Normal_Enemy::~Normal_Enemy() {};
void Normal_Enemy::Interaction(Enemy* m_Enemy, float fPlayerPosX, float fPlayerPosY, float fDeltaTime) {
	float fEnemyPosX = m_Enemy->GetPhysicsBody()->GetWorldCenter().x * PIXELS_METERS;
	float fEnemyPosY = m_Enemy->GetPhysicsBody()->GetWorldCenter().y * PIXELS_METERS;
	m_Enemy->fDistanceY = sqrt((fPlayerPosY - fEnemyPosY) * (fPlayerPosY - fEnemyPosY));
	m_Enemy->fDistanceX = sqrt((fPlayerPosX - fEnemyPosX) * (fPlayerPosX - fEnemyPosX));
	m_Enemy->fDistance = sqrt((m_Enemy->fDistanceX * m_Enemy->fDistanceX) + (m_Enemy->fDistanceY * m_Enemy->fDistanceY));
	if (m_Enemy->fDistance < 500) {
		if (fPlayerPosX < fEnemyPosX && fPlayerPosY < fEnemyPosY) {
			if (m_Enemy->fDistance < 70 && (m_Enemy->fDistanceX < 1 || m_Enemy->fDistanceY < 1)) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, -1);
			}
			else if (m_Enemy->fDistanceX < 1) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 1);
				if (m_Enemy->fDistanceY < 70) {
					m_Enemy->Stop(fDeltaTime, 4);
					m_Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY > 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 2);
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY < 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 1);
			}
			else {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 2);
				m_Enemy->Move(fDeltaTime, 1);
			}
		}
		if (fPlayerPosX < fEnemyPosX && fPlayerPosY > fEnemyPosY) {
			if (m_Enemy->fDistance < 70 && (m_Enemy->fDistanceX < 1 || m_Enemy->fDistanceY < 1)) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, -1);
			}
			else if (m_Enemy->fDistanceX < 1) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 0);
				if (m_Enemy->fDistanceY < 70) {
					m_Enemy->Stop(fDeltaTime, 4);
					m_Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY > 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 2);
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY < 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 0);
			}
			else {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 2);
				m_Enemy->Move(fDeltaTime, 0);
			}
		}
		if (fPlayerPosX > fEnemyPosX && fPlayerPosY < fEnemyPosY) {
			if (m_Enemy->fDistance < 70 && (m_Enemy->fDistanceX < 1 || m_Enemy->fDistanceY < 1)) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, -1);
			}
			else if (m_Enemy->fDistanceX < 1) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 1);
				if (m_Enemy->fDistanceY < 70) {
					m_Enemy->Stop(fDeltaTime, 4);
					m_Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY > 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 3);
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY < 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 1);
			}

			else {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 3);
				m_Enemy->Move(fDeltaTime, 1);
			}
		}
		if (fPlayerPosX > fEnemyPosX && fPlayerPosY > fEnemyPosY) {
			if (m_Enemy->fDistance < 70 && (m_Enemy->fDistanceX < 1 || m_Enemy->fDistanceY < 1)) {
				m_Enemy ->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, -1);
			}
			else if (m_Enemy->fDistanceX < 1) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 0);
				if (m_Enemy->fDistanceY < 70) {
					m_Enemy->Stop(fDeltaTime, 4);
					m_Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY > 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 3);
			}
			else if (m_Enemy->fDistanceX < 70 && m_Enemy->fDistanceY < 70) {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 0);
			}
			else {
				m_Enemy->Stop(fDeltaTime, 4);
				m_Enemy->Move(fDeltaTime, 3);
				m_Enemy->Move(fDeltaTime, 0);
			}
		}

	}
	else {
		m_Enemy->Stop(fDeltaTime, 4);
		m_Enemy->Move(fDeltaTime, -1);
	}
}