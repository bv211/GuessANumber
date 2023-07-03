#pragma once
#include <Windows.h>
#include "Player.h"

class ComputerPlayer : public Player {
public:
	ComputerPlayer(const string& name) : Player(name) {}

	virtual int get_value(int max) override {
		Sleep(1000);
		srand(time(NULL));
		return rand() % max;
	}
};