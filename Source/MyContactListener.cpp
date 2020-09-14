// Precompiled Headers
#include "stdafx.h"

#include "MyContactListener.h"

void MyContactListener::BeginContact(b2Contact* contact) {
    //check if fixture A was a ball
    void* bodyDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    
	if (!bodyDataA) return;
	if (!bodyDataB) return;

	MyObject* objectA = static_cast<MyObject*>(bodyDataA);
	MyObject* objectB = static_cast<MyObject*>(bodyDataB);

	if (objectB->GetObjectType() == ObjectType::PROJECTILE) {
		Projectile* ProjectileB = static_cast<Projectile*>(objectB);
		switch (objectA->GetObjectType())
		{
		case ObjectType::ENEMY: {
			printf("Hit Enemy!\n");
			Enemy* EnemyA = static_cast<Enemy*>(objectA);
			EnemyA->Damaged(ProjectileB->GetDamage());
			ProjectileB->Death();
			break;
		}
		case ObjectType::WALL: {
			printf("Hit Wall!\n");
			ProjectileB->Death();
			break;
		}
		default:
			break;
		}
	}
}

void MyContactListener::EndContact(b2Contact* contact) {
    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if (bodyUserData) {
    };

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if (bodyUserData) {
    };
}