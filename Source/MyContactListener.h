#pragma once

// Precompiled Headers
#include "stdafx.h"

// External Libraries
#include "Box2D/Box2D.h"

// Local
#include "MyObject.h"
#include "Wall.h"
#include "Ground.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Projectile.h"

class MyContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};