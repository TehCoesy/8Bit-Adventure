#include "stdafx.h"
#include "Normal_Enemy.h"

Normal_Enemy::Normal_Enemy() {};
Normal_Enemy::~Normal_Enemy() {};
void Normal_Enemy::Interaction(Enemy*Enemy,float fPlayerPosX, float fPlayerPosY,float fDeltaTime) {
	float fEnemyPosX = Enemy->GetPhysicsBody()->GetWorldCenter().x * PIXELS_METERS;
	float fEnemyPosY = Enemy->GetPhysicsBody()->GetWorldCenter().y * PIXELS_METERS;
	Enemy->fDistanceY = sqrt((fPlayerPosY - fEnemyPosY)*(fPlayerPosY - fEnemyPosY));
	Enemy->fDistanceX = sqrt((fPlayerPosX - fEnemyPosX)*(fPlayerPosX - fEnemyPosX));
	Enemy->fDistance = sqrt((Enemy->fDistanceX * Enemy->fDistanceX) + (Enemy->fDistanceY *Enemy->fDistanceY));
	if (Enemy->fDistance < 500) {
		if (fPlayerPosX <fEnemyPosX && fPlayerPosY < fEnemyPosY) {
			if (Enemy->fDistance < 70 && (Enemy->fDistanceX <1 || Enemy->fDistanceY <1)) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, -1);
			}
			else if (Enemy->fDistanceX < 1) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 1);
				if (Enemy->fDistanceY < 70) {
					Enemy->Stop(fDeltaTime, 4);
					Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY > 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 2);
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY < 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 1);
			}
			else {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 2);
				Enemy->Move(fDeltaTime, 1);
			}
		}
		if (fPlayerPosX < fEnemyPosX && fPlayerPosY > fEnemyPosY) {
			if (Enemy->fDistance < 70 && (Enemy->fDistanceX <1 || Enemy->fDistanceY <1)) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, -1);
			}
			else if (Enemy->fDistanceX < 1) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 0);
				if (Enemy->fDistanceY < 70) {
					Enemy->Stop(fDeltaTime, 4);
					Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY > 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 2);
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY < 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 0);
			}
			else {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 2);
				Enemy->Move(fDeltaTime, 0);
			}
		}
		if (fPlayerPosX > fEnemyPosX && fPlayerPosY < fEnemyPosY) {
			if (Enemy->fDistance < 70 && (Enemy->fDistanceX <1 || Enemy->fDistanceY <1)) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, -1);
			}
			else if (Enemy->fDistanceX < 1) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 1);
				if (Enemy->fDistanceY < 70) {
					Enemy->Stop(fDeltaTime, 4);
					Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY > 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 3);
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY < 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 1);
			}

			else {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 3);
				Enemy->Move(fDeltaTime, 1);
			}
		}
		if (fPlayerPosX > fEnemyPosX && fPlayerPosY > fEnemyPosY) {
			if (Enemy->fDistance < 70 && (Enemy->fDistanceX <1 || Enemy->fDistanceY <1)) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, -1);
			}
			else if (Enemy->fDistanceX < 1) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 0);
				if (Enemy->fDistanceY < 70) {
					Enemy->Stop(fDeltaTime, 4);
					Enemy->Move(fDeltaTime, -1);
				}
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY > 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 3);
			}
			else if (Enemy->fDistanceX < 70 && Enemy->fDistanceY < 70) {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 0);
			}
			else {
				Enemy->Stop(fDeltaTime, 4);
				Enemy->Move(fDeltaTime, 3);
				Enemy->Move(fDeltaTime, 0);
			}
		}

	}
	else {
		Enemy->Stop(fDeltaTime, 4);
		Enemy->Move(fDeltaTime, -1);
	}
}