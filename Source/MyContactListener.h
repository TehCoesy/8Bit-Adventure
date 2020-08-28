#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "MyObject.h"
#include "DynamicObject.h"

class MyContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};