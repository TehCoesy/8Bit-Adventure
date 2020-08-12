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

	void LoadGameScene(GameScene* GameScene, std::string strFilePath);
	void LoadMainMenu();
};