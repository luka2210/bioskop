#pragma once
#include <string>

using namespace std;

class Sala
{
public:
	int id;
	string *termini;
	int brojSlobodnihMesta;

	Sala(int id, string *termini, int brojSlobodnihMesta) {
		this->id = id;
		this->termini = termini;
		this->brojSlobodnihMesta = brojSlobodnihMesta;
	}

	Sala() {
		this->id = 0;
		this->termini = {};
		this->brojSlobodnihMesta = 0;
	}
};

