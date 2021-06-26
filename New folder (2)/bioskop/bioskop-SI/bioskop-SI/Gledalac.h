#pragma once
#include <string>

using namespace std;

class Gledalac
{
public:
	string username;
	string sifra;
	string email;

	Gledalac(string username, string sifra, string email) {
		this->username = username;
		this->sifra = sifra;
		this->email = email;
	}

	Gledalac() {
		this->username = "";
		this->sifra = "";
		this->email = "";
	}
};

