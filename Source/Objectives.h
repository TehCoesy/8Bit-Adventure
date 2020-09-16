#pragma once

#include "stdafx.h"

class Objectives {
public:
	enum type { CLEAR_STAGE_IN_TIME = 0, LOSE_HP_LESS_THAN = 1, DIE_LESS_THAN = 2 };
	void SetValue(type t) {
		this->value = t;
	}
	type GetValue() {
		return value;
	}
private:
	type value;
};