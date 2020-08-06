#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "Singleton.h"

class SceneManager : public Singleton<SceneManager> {
private:
public:
	void Init();
};