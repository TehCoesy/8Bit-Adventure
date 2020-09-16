#include "stdafx.h"

#include "SettingArg.h"

SettingArg::SettingArg() {
	this->dif = 1;
	this->mod = 0;
	this->start_time = 0;
}

SettingArg::~SettingArg() {

}

void SettingArg::setDif(int dif) {
	this->dif = dif;
}

void SettingArg::setMod(int mod) {
	this->mod = mod;
}

int SettingArg::getDif() {
	return this->dif;
}

int SettingArg::getMod() {
	return this->mod;
}

int SettingArg::getTime() {
	return this->start_time;
}

void SettingArg::setTime(time_t time) {
	this->start_time = time;
}