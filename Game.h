#pragma once
#include "Player.h"

class Game {
	int _max_value;
	int _try_count;
	int _guess_number{};

	Player* _player_1;
	Player* _player_2;
	Player* _winner{ nullptr };

public:
	Game(int _max_value, int try_count, Player* _player_1, Player* _player_2)
		: _max_value(_max_value), _try_count(try_count), _player_1(_player_1), _player_2(_player_2) {}

	void start_game() {
		srand(time(NULL));
		_guess_number = rand() % _max_value;

		for (size_t i = 0; i < _try_count; i++) {
			move_player(_player_1);
			if (_winner != nullptr) break;

			move_player(_player_2);
			if (_winner != nullptr) break;
		}

		end_game();
	}

private:
	void move_player(Player* player) {
		cout << "Ходит " << player->get_name() << endl;

		auto value = get_value(player);
		cout << "Выбрал: " << value << endl << endl;

		if (check_value(value)) set_winner(player);
	}

	void end_game() {
		if (_winner == nullptr)
			cout << "Оба проиграли" << endl;
		else
			cout << "Победил " << _winner->get_name() << endl;

		cout << "Число " << _guess_number << endl;
	}

	bool check_value(int value) {
		return value == _guess_number;
	}

	int get_value(Player* player) {
		return player->get_value(_max_value);
	}

	void set_winner(Player* player) {
		_winner = player;
	}
};