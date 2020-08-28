// Precompiled Headers
#include "stdafx.h"

#include "Attack.h"

Attack::Attack() {

}

Attack::Attack(int iOwnerID, b2Body* SensorBody) {
	m_iOwnerID = iOwnerID;
	m_SensorBody = SensorBody;
}

Attack::Attack(const Attack& cObject) {
	m_iOwnerID = cObject.m_iOwnerID;
	m_SensorBody = cObject.m_SensorBody;
}

Attack::~Attack() {

}

void Attack::Update(float fDeltaTime) {
	m_iCount++;
	if (m_iCount == m_iSteps) {
		Finish();
	}
}

void Attack::Finish() {
	m_bDone = true;
	// Safely delete SensorBody
	m_SensorBody->GetWorld()->DestroyBody(m_SensorBody);
}

bool Attack::IsFinished() {
	return m_bDone;
}