#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "MyContactListener.h"

class Attack {
private:
	int m_iOwnerID = -1;
	b2Body* m_SensorBody;
public:
	Attack();
	Attack(int iOwnerID, b2Body* SensorBody);
	Attack(const Attack& cObject);
	~Attack();
};