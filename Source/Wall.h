#pragma once

// Precompiled Headers
#include "stdafx.h"

#include "MyObject.h"

class Wall : public MyObject {
private:
public:
	Wall();
	Wall(int iID, std::string strName, MyTexture NewTexture, b2Body* PhysicsBody);
	Wall(const Wall& cObject);
	~Wall();
};