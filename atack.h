#ifndef _Atack_
#define _Atack_

#include <iostream>
using namespace std;

class Atack {

private:
	string nome;
	string sound;
	int damage;

public:
	Atack(string _nome, string _sound, int damage);
	string getNome();
	string getSound();
	int getDamage();
};

#endif //_Atack_
