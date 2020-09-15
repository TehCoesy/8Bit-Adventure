#pragma once

#include "stdafx.h"

#include "Singleton.h"

class SettingArg : public Singleton<SettingArg> {
private:
	int dif; //0: Easy 1: Normal 2: Hard
	int mod; //0: Normal 1: Infinity
public:
	SettingArg();
	~SettingArg();
	void setDif(int dif);
	void setMod(int mod);
	int getDif();
	int getMod();
};