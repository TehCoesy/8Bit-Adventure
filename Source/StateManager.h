#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "Singleton.h"

class StateManager : public Singleton<StateManager> {
private:
public:
	StateManager();
	~StateManager();
};