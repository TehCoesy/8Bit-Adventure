#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "Singleton.h"
#include "GameScene.h"
#include "MainMenu.h"

class SceneManager : public Singleton<SceneManager> {
private:
public:
	SceneManager();
	~SceneManager();

	GameScene m_GameScene;

	void Init();

	void LoadGameScene(std::string strFilePath);
	void LoadMainMenu();
};