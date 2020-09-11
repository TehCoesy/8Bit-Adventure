// Precompiled Headers
#include "stdafx.h"

#include "Player.h"

Player::Player() {

}

Player::Player(int iID, std::string strName, std::string strAnimationName, b2Body* PhysicsBody, b2Vec2 fSizeP) {
	// Always do the following:
	// + Setup object's identity
	// + Setup object's state
	// + m_bIsActive / m_bCanMove / m_bIsDead;
	// + Setup object's m_PhysicsBody
	// + Setup object's Animation / Texture
	// + Setup sprite's m_fSizeP and setup proper origin (!Important) (call SetSpriteChanged() and SynchronizeBody())
	// + Setup m_fMaxVelocity (if needed) (default is 5.0f)
	
	// Setup object's identity
	m_iID = iID;
	m_strName = strName;
	m_ObjectType = ObjectType::PLAYER;

	// Setup object's state
	m_ObjectState = ObjectState::IDLE;
	m_bIsActive = true;

	// Setup object's m_PhysicsBody
	m_PhysicsBody = PhysicsBody;
	m_PhysicsBody->SetUserData(this);

	// Setup object's Animation
	m_Animation = RM->GetAnimation(strAnimationName);
	m_Animation.Play();

	m_Animation.Fetch(&m_Sprite);

	// Setup sprite's size + origin
	m_fSizeP = fSizeP;
	SetSpriteChanged();

	SynchronizeBody();

	// Debug
	m_DebugBox.setFillColor(sf::Color::Transparent);
	m_DebugBox.setOutlineColor(sf::Color::Red);
	m_DebugBox.setOutlineThickness(1.0f);
	m_DebugBox.setSize(sf::Vector2f(64.0f, 64.0f));
	m_DebugBox.setOrigin(sf::Vector2f(32.0f, 32.0f));
}

Player::~Player() {
	DestroyBody();
}

void Player::Update(float fDeltaTime) {
	if (m_iID != -1) {
		float fCurrentVelocityX = m_PhysicsBody->GetLinearVelocity().x;
		float fCurrentVelocityY = m_PhysicsBody->GetLinearVelocity().y;

		if (fCurrentVelocityX == 0.0f && fCurrentVelocityY == 0.0f) {
			if (m_iDirection == 0 && *m_Animation.GetName() != "PLAYER_IDLE_DOWN") {
				NewAnimation("PLAYER_IDLE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "PLAYER_IDLE_UP") {
				NewAnimation("PLAYER_IDLE_UP");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "PLAYER_IDLE_LEFT") {
				NewAnimation("PLAYER_IDLE_LEFT");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "PLAYER_IDLE_RIGHT") {
				NewAnimation("PLAYER_IDLE_RIGHT");
			}
		}
		else {
			if (m_iDirection == 0 && *m_Animation.GetName() != "PLAYER_MOVE_DOWN") {
				NewAnimation("PLAYER_MOVE_DOWN");
			}
			else if (m_iDirection == 1 && *m_Animation.GetName() != "PLAYER_MOVE_UP") {
				NewAnimation("PLAYER_MOVE_UP");
			}
			else if (m_iDirection == 2 && *m_Animation.GetName() != "PLAYER_MOVE_LEFT") {
				NewAnimation("PLAYER_MOVE_LEFT");
			}
			else if (m_iDirection == 3 && *m_Animation.GetName() != "PLAYER_MOVE_RIGHT") {
				NewAnimation("PLAYER_MOVE_RIGHT");
			}
		}
		
		m_Animation.Update(fDeltaTime);
		m_Animation.Fetch(&m_Sprite);
		SynchronizeBody();

		// Debug
		if (m_bDebugDraw) {
			m_DebugBox.setPosition(m_PhysicsBody->GetPosition().x * PIXELS_METERS, m_PhysicsBody->GetPosition().y * PIXELS_METERS);
			m_DebugBox.setRotation(Radian2Degree(m_PhysicsBody->GetAngle()));
		}

		// Stop movement 
		Move(fDeltaTime, -1);
	}
}

void Player::Render(sf::RenderWindow* RenderWindow) {
	if (m_iID != -1) {
		float WorldPositionX = m_Sprite.getPosition().x;
		float WorldPositionY = m_Sprite.getPosition().y;

		m_Sprite.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
		RenderWindow->draw(m_Sprite);
		m_Sprite.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));

		if (m_bDebugDraw) {
			WorldPositionX = m_DebugBox.getPosition().x;
			WorldPositionY = m_DebugBox.getPosition().y;

			m_DebugBox.setPosition(sf::Vector2f(WorldPositionX + MainCamera->GetCameraVector().x, WorldPositionY + MainCamera->GetCameraVector().y));
			RenderWindow->draw(m_DebugBox);
			m_DebugBox.setPosition(sf::Vector2f(WorldPositionX, WorldPositionY));
		}
	}
}