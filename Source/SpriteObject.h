#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class SpriteObject : public MyObject {
private:
	SpriteObject(SpriteObject const&) = delete;
	SpriteObject& operator=(SpriteObject const&) = delete;
protected:
	// Graphics
	sf::Sprite m_Sprite;

	MyTexture m_StaticTexture;
	Animation m_Animation;

	// Fetch new Animation / Texture from RM
	void NewAnimation(std::string strName);
	void NewTexture(std::string strName);

	// Synchronize Sprite with PhysicsBody
	void SynchronizeBody();

	bool m_bSpriteChanged = false;
	void SetSpriteChanged();
public:
	SpriteObject();
	~SpriteObject();

	virtual void Update(float fDeltaTime);
	virtual void Render(sf::RenderWindow* MainWindow);
};