#ifndef _Player_
#define _Player_

#include <iostream>
#include <vector>
#include "pokemon.h"
#include "Tipos.h"


using namespace std;

class Player{
private:
	string nome;
	string sound;
	string image;
	vector<Pokemon> pokemons;

public:
	Player(string _nome, string _sound, string _image);
	Player();
	string getNome();
	void setNome(string nome);
	string getSound();
	string getImage();
	void addPokemon(Pokemon p);
	bool getFimJogo();
};
#endif _Player_
