#include "pokemon.h"


Pokemon::Pokemon(string _nome, string _tipo, int _life, int _exp, string _color, string _sound, string _image, vector<Atack> _atacks){
	nome = _nome;
	tipo = _tipo;
	life = _life;
	exp = _exp;
	color = _color;
	sound = _sound;
	image = _image;
	atacks = _atacks;
}



string Pokemon::getNome() {
	return nome;
}

string Pokemon::getColor() {
	return color;
}

string Pokemon::getTipo() {
	return tipo;
}

string Pokemon::getSound() {
	return sound;
}

string Pokemon::getImage() {
	return image;
}

vector<Atack> Pokemon::getAtacks() {
	return atacks;
}