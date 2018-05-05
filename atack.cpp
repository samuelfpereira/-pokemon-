#include "atack.h"

Atack::Atack(string _nome, string _sound, int _damage) {
	nome = _nome;
	sound = _sound;
	damage = _damage;
}


string Atack::getNome() {
	return nome;
}

string Atack::getSound() {
	return sound;
}

int Atack::getDamage() {
	return damage;
}