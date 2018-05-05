#ifndef _Pokemon_
#define _Pokemon_

#include <iostream>
#include "atack.h"
#include <vector>
using namespace std;

class Pokemon{
private:
	string nome;
	string tipo;
	int life;
	int exp;
	string color;
	string sound;
	string image;
	vector<Atack> atacks;

public:
	Pokemon(string _nome, string _tipo, int _life, int _exp, string _color, string _sound, string _image, vector<Atack> atacks);
	string getNome();
	string getColor();
	string getSound();
	string getTipo();
	string getImage();
	vector<Atack> getAtacks();
};
#endif _Pokemon_