// Precompiled Headers
#include "stdafx.h"

#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(int iID, std::string strName, std::string strEnemyType, b2Body* physicsBody, b2Vec2 fSizeP, int health, int scores, int damage,Player* player) {
	// Setup object's identity
	m_iID = iID;
	m_strName = strName;
	m_ObjectType = ObjectType::ENEMY;

	// Setup object's state
	m_ObjectState = ObjectState::IDLE;
	m_bIsActive = true;

	// Setup object's m_PhysicsBody
	m_PhysicsBody = physicsBody;
	m_PhysicsBody->SetUserData(this);

	// Setup object's Animation
	m_Animation = RM->GetAnimation("SKELE_IDLE_DOWN");
	m_Animation.Play();
	
	m_Animation.Fetch(&m_Sprite);

	// Setup sprite's size + origin
	m_fSizeP = fSizeP;
	SetSpriteChanged();

	SynchronizeBody();

	m_fMaxVelocity = 1.0f;

	m_iScores = (float)scores;
	m_iDamage = (float)damage;
	m_iHealth = (float)health;

	int dif = SettingArg::GetInstance()->getDif();
	if (dif == 0) {
		m_iDamage *= 0.5;
		m_iScores *= 0.5;
		m_iHealth *= 0.5;
	}
	else  if (dif == 2) {
		m_iDamage *= 2;
		m_iScores *= 2;
		m_iHealth *= 3;
	}
	max_iHealth = m_iHealth;
	this->player = player;
	ping = 0;
}

Enemy::~Enemy() {
	DestroyBody();
}



void Enemy::Update(float fDeltaTime) {
	if (m_ObjectState == ObjectState::DEATH) {
		CompleteStop(fDeltaTime);
		m_bCanMove = false;
		if (m_Animation.IsDone()) {
			Destroy();
		}
	}

	if (m_iID != -1 && m_ObjectState != ObjectState::DEATH) {
		float distance = sqrt(pow(player->GetPhysicsBody()->GetWorldCenter().x - this->GetPhysicsBody()->GetWorldCenter().x, 2) + pow(player->GetPhysicsBody()->GetWorldCenter().y - this->GetPhysicsBody()->GetWorldCenter().y, 2));
		if (distance < 4.0f) {
			if (!ping) player->Damaged(this->GetDamage());
			ping++;
		}
		if (ping >= 100) ping = 0;
		float fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
		float fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;
		if (fCurrentVelocityX == 0.0f && fCurrentVelocityY == 0.0f) {
			if (m_iDirection == 0 && *m_Animation.GetName() != "SKELE_IDLE_DOWN") {
				NewAnimation("SKELE_IDLE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "SKELE_IDLE_UP") {
				NewAnimation("SKELE_IDLE_UP");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "SKELE_IDLE_LEFT") {
				NewAnimation("SKELE_IDLE_LEFT");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "SKELE_IDLE_RIGHT") {
				NewAnimation("SKELE_IDLE_RIGHT");
			}
		}
		else {
			if (m_iDirection == 0 && *m_Animation.GetName() != "SKELE_MOVE_DOWN") {
				NewAnimation("SKELE_MOVE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "SKELE_MOVE_UP") {
				NewAnimation("SKELE_MOVE_UP");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "SKELE_MOVE_LEFT") {
				NewAnimation("SKELE_MOVE_LEFT");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "SKELE_MOVE_RIGHT") {
				NewAnimation("SKELE_MOVE_RIGHT");
			}
		}
	}

	m_Animation.Update(fDeltaTime);
	m_Animation.Fetch(&m_Sprite);
	SynchronizeBody();
}

void Enemy::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		fDistance = 9999999;
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;
		//m_Sprite.setPosition(sf::Vector2f(600, 600));
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
		sf::RectangleShape hpBarBack;
		sf::RectangleShape hpBarInside;
		hpBarBack.setSize(sf::Vector2f(40.0f, 5.0f));
		hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
		hpBarBack.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x - 20.0f, WorldPositionY + MainCamera->GetCameraVector().y - 35.0f));

		hpBarInside.setSize(sf::Vector2f(40.0*getHealth()/getMaxHealth(), 5.0f));
		hpBarInside.setFillColor(sf::Color(250, 50, 50, 200));
		hpBarInside.setPosition(hpBarBack.getPosition());
		RenderWindow->draw(hpBarBack);
		RenderWindow->draw(hpBarInside);
	}
}

void Enemy::Death() {
	if (m_ObjectState != ObjectState::DEATH && m_ObjectState != ObjectState::DESTROYED) {
		m_ObjectState = ObjectState::DEATH;
		switch (m_iDirection) {
		case 0: m_Animation = RM->GetAnimation("SKELETON_DIE_DOWN"); break;
		case 1: m_Animation = RM->GetAnimation("SKELETON_DIE_UP"); break;
		case 2: m_Animation = RM->GetAnimation("SKELETON_DIE_LEFT"); break;
		case 3: m_Animation = RM->GetAnimation("SKELETON_DIE_RIGHT"); break;
		}

		if (m_Animation.IsRepeating()) {
			m_Animation.ToggleRepeat();
		}
	}
}

void Enemy::Destroy() {
	m_bIsActive = false;
	m_ObjectState = ObjectState::DESTROYED;
}

void Enemy::Damaged(int damage)
{
	m_Animation.BlinkForFrames(100);
	m_iHealth -= damage;
	if (m_iHealth <= 0) {
		m_iHealth = 0;
		Death();
	}
	SM->PlayEffectByName("ENEMY_HURT");
}