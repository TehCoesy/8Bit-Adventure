// Precompiled Headers
#include "stdafx.h"

#include "GameScene.h"

GameScene::GameScene() {

}

GameScene::~GameScene() {

}

bool GameScene::IsSetup() {
	if (m_World != nullptr) {
		return false;
	}
	return true;
}

void GameScene::AddObject(MyObject NewObject) {

}

void GameScene::Update(float fDeltaTime) {

}

void GameScene::Render() {

}