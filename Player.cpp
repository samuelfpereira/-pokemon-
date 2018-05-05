#include "Player.h"


Player::Player(string _nome, string _sound, string _image) {
	nome = _nome;
	sound = _sound;
	image = _image;
}

Player::Player() {
}

string Player::getNome() {
	return nome;
}

void Player::setNome(string nome) {
	this->nome = nome;
}

string Player::getSound() {
	return sound;
}

string Player::getImage() {
	return image;
}

void Player::addPokemon(Pokemon p) {
	pokemons.push_back(p);
	Player::getFimJogo();
}

bool Player::getFimJogo() {
	int e = 0, a = 0, f = 0, er = 0;
	for (int j = 0; j < pokemons.size(); j++) {

		if (pokemons[j].getTipo() == "Agua") {
			a++;
		}
		if (pokemons[j].getTipo() == "Eletrico") {
			e++;
		}
		if (pokemons[j].getTipo() == "Erva") {
			er++;
		}
		if (pokemons[j].getTipo() == "Fogo") {
			f++;
		}
	}
	cout << "Pokemons do Tipo Fogo: " << f << endl;
	cout << "Pokemons do Tipo Agua: " << a << endl;
	cout << "Pokemons do Tipo Eletrico: " << e << endl;
	cout << "Pokemons do Tipo Erva: " << er << endl;


	if (er >= 1 && e >= 1 && a >= 1 && f >= 1) {
		return 1;
	}
	else {
		return 0;
	}
}