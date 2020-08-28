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