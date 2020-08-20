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

#define TILE_SIZE 64.0f
#define PIXELS_METERS 30.0f

//Animation
#define OBJECT_IDLE_UP 0
#define OBJECT_IDLE_DOWN 1
#define OBJECT_IDLE_LEFT 2
#define OBJECT_IDLE_RIGHT 3