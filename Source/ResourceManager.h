#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "Singleton.h"

class ResourceManager : public Singleton<ResourceManager> {
private:
public:
	void Init();
};