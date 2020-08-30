#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class SensorObject : public MyObject {
private:
	bool m_bSensorDebug = true;
public:
	SensorObject();
	~SensorObject();
};