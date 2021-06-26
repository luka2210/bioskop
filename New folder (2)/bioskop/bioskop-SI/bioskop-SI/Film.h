#pragma once
#include <string>

using namespace std;

class Film
{
public:
	int id;
	string naziv;
	int sala;

	Film(int id, string naziv, int sala) {
		this->id = id;
		this->naziv = naziv;
		this->sala = sala;
	}

	Film() {
		this->id = 0;
		this->naziv = "";
		this->sala = 0;
	}
};

