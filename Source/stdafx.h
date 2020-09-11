#pragma once

// Local
#include <stdio.h>
#include <string>
#include <vector>

// Macros
#define WINDOW_W 800
#define WINDOW_H 800
#define WINDOW_TITLE "Chronicle: Rise"
#define FRAMERATE 60.0f

#define RESOURCESFOLDER "./Resources/"

#define RM ResourceManager::GetInstance()
#define SM SoundManager::GetInstance()

#define GameSceneInstance GameScene::GetInstance()
#define MainMenuInstance MainMenu::GetInstance()
#define MainCamera Camera::GetInstance()
#define StateMachine StateManager::GetInstance()

#define TILE_SIZE 64.0f
#define PIXELS_METERS 30.0f

#define MAINMENU_BACKGROUND "Resources/Textures/bg/main.jpg"
#define GAMESCENE_FILEPATH "./Resources/Stage1.txt"
#define STAGE1_TERRAIN_FILEPATH "Stage1_Terrain.txt"

#define FONT_VIDEOPHREAK "Resources/Font/VIDEOPHREAK.ttf"
#define FONT_FONT2 "Resources/Font/font2.ttf"

//Animation
#define OBJECT_IDLE_UP 0
#define OBJECT_IDLE_DOWN 1
#define OBJECT_IDLE_LEFT 2
#define OBJECT_IDLE_RIGHT 3