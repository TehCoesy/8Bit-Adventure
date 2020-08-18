#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "Singleton.h"
#include "MyObject.h"

class MainMenu {
private:
public:
	MainMenu();
	~MainMenu();

	void LoadFromFile(std::string strFilePath);
};