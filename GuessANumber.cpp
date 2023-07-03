#include <iostream>
#include <Windows.h>
#include "Game.h"
#include "Player.h"
#include "ComputerPlayer.h"

using namespace std;

int main() {
	setlocale(0, "rus");

	Player real_player("Player");
	ComputerPlayer comp_player("Comp");

	Game game(20, 5, &real_player, &comp_player);
	game.start_game();

	return 0;
}