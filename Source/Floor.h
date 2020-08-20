#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class Floor : public MyObject {
private:
public:
	Floor();
	Floor(int iID, std::string strName, MyTexture NewTexture, b2Body* PhysicsBody);
	Floor(const Floor& cObject);
	~Floor();
};