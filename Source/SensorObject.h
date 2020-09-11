#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "MyObject.h"

class SensorObject : public MyObject {
private:
	SensorObject(SensorObject const&) = delete;
	SensorObject& operator=(SensorObject const&) = delete;

	bool m_bSensorDebug = true;
public:
	SensorObject();
	~SensorObject();
};