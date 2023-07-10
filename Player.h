#pragma once
#include <iostream>

using namespace std;

namespace Players {
	class Player {
		string _name;

	public:
		Player(const string& name) : _name(name) { }

		virtual int get_value(int max) {
			int value;
			do
			{
				cin >> value;
			} while (value < 0 || value > max);

			return value;
		}

		string get_name() const {
			return _name;
		}
	};
}
