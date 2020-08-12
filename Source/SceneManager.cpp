// Precompiled Headers
#include "stdafx.h"

#include "SceneManager.h"

SceneManager::SceneManager() {

}

SceneManager::~SceneManager() {

}

void SceneManager::LoadGameScene(GameScene* GameScene, std::string strFilePath) {
	FILE* FileStream;
	strFilePath = RESOURCESFOLDER + strFilePath;
	FileStream = fopen(strFilePath.c_str(), "r");

	if (FileStream) {
		// PlaceHolder Scene, for testing;

		// Close FileStream
		fclose(FileStream);
	}
}

void SceneManager::LoadMainMenu() {

}