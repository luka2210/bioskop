#pragma once
#include <string>

using namespace std;

class Zaposleni
{
public:
	int id;
	string ime;
	string prezime;

	Zaposleni(string ime, string prezime) {
		this->ime = ime;
		this->prezime = prezime;
		this->id = rand() % 100;
	}

	Zaposleni() {
		this->ime = "";
		this->prezime = "";
		this->id = 0;
	}
};

