#pragma once

#include "stdafx.h"

#include "Singleton.h"
#include "Objectives.h"

class SettingArg : public Singleton<SettingArg> {
private:
	int dif; //0: Easy 1: Normal 2: Hard
	int mod; //0: Normal 1: Infinity
	time_t start_time;
public:
	SettingArg();
	~SettingArg();
	void setDif(int dif);
	void setMod(int mod);
	int getDif();
	int getMod();
	int getTime();
	void setTime(time_t time);
	std::vector<std::pair<Objectives, int>> m_Objectives;
};