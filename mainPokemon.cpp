#include <iostream> //Default lib
#include <fstream> //Default lib
#define _WIN32_WINNT 0x500 //Maximize Window
#pragma comment(lib, "winmm.lib") //added for sound linker
#include <windows.h> //Libray for Windows functions
#include <mmsystem.h> //Libary for multimedia use 
#include <cstdlib>  // to use a random number generator
#include <ctime>    // to get the current time
#include <dos.h> //allows "delay / sleep" action
#include <conio.h>
#include <vector>
#include <string>

#include "pokemon.h"
#include "Player.h"

using namespace std;


//ola

void INTRO() {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	mciSendString("play PokemonMenu\\Opening.mp3 repeat", NULL, 0, 0);
	cout << "		Projeto por: Samuel Pereira - a81408			\n";
	Sleep(2100);
	system("Cls");

	char s[1024];
	fstream filelogo("PokemonMenu\\PokemonLogo.txt");
	while (filelogo.getline(s, 1024))
	{
		cout << s << endl;
	}
	system("color E");
	filelogo.close();

	system("pause");
	mciSendString("stop PokemonMenu\\Opening.mp3", NULL, 0, 0);
	system("CLs");
	system("color F");
}


void createPokemons(vector<Pokemon> &defaultPokemons) {

	vector<Atack> atackPikachu;
	vector<Atack> atackSquirtle;
	vector<Atack> atackCharmander;
	vector<Atack> atackBulbasaur;

	Atack Tackle = Atack("Tackle", "PokemonAtacks\\Tackle.mp3", 20);
	Atack Thunder = Atack("Thunder", "PokemonAtacks\\Thunder.mp3", 70);
	Atack WaterGun = Atack("Water Gun", "PokemonAtacks\\WaterGun.mp3", 50);
	Atack Ember = Atack("Ember", "PokemonAtacks\\Ember.mp3", 50);
	Atack RazorLeaf = Atack("Razor Leaf", "PokemonAtacks\\RazorLeaf.mp3", 50);


	atackPikachu.push_back(Tackle);
	atackPikachu.push_back(Thunder);

	atackSquirtle.push_back(Tackle);
	atackSquirtle.push_back(WaterGun);

	atackCharmander.push_back(Tackle);
	atackCharmander.push_back(Ember);

	atackBulbasaur.push_back(Tackle);
	atackBulbasaur.push_back(RazorLeaf);

	//bool para definir se é inicial ou nao-------------------------------------------------------------------------------------------------------------------------------

	Pokemon p = Pokemon("Pikachu", "Eletrico", 100, 0, "E", "PokemonSoundClips\\Pikachu.mp3", "Characters\\Pikachu.txt", atackPikachu);
	Pokemon s = Pokemon("Squirtle", "Agua", 100, 0, "3", "PokemonSoundClips\\Squirtle.mp3", "Characters\\Squirtle.txt", atackSquirtle);
	Pokemon c = Pokemon("Charmander", "Fogo", 100, 0, "C", "PokemonSoundClips\\Charmander.mp3", "Characters\\Charmander.txt", atackCharmander);
	Pokemon b = Pokemon("Bulbasaur", "Erva", 100, 0, "A", "PokemonSoundClips\\Bulbasaur.mp3", "Characters\\Bulbasaur.txt", atackBulbasaur);

	defaultPokemons.push_back(p);
	defaultPokemons.push_back(s);
	defaultPokemons.push_back(c);
	defaultPokemons.push_back(b);
}

void createlistaPlayers(vector<Player> &listaPlayer) {

	Player b = Player("Rapaz", "Playersound\\male.mp3", "PokemonPlayer\\ash.txt");
	Player g = Player("Rapariga", "Playersound\\female.mp3", "PokemonPlayer\\misty.txt");

	listaPlayer.push_back(b);
	listaPlayer.push_back(g);
}

void PrintPokemonAndSound(Pokemon p) {

	string color = "color " + p.getColor();
	system(color.c_str());

	cout << ">>>>>>>>>>	" << p.getNome() << "	    <<<<<<<<<<\n" << endl;


	string c = "play " + p.getSound();
	mciSendString(c.c_str(), NULL, 0, NULL);
	char s[1024];
	fstream fh(p.getImage());
	while (fh.getline(s, 1024))
	{
		cout << s << endl;
	}
	system("pause");
	fh.close();
	cout << "\n";
}

void PrintPlayerAndSound(Player &p) {

	string nome;

	string textonome = "Qual o seu nome?\n";
	for (int i = 0; i < textonome.size(); i++)
	{
		Sleep(100);
		cout << textonome[i];
	}

	cin >> nome;
	p.setNome(nome);

	cout << ">>>>>>>>>>	" << p.getNome() << "	 <<<<<<<<<<\n" << endl;


	string c = "play " + p.getSound();
	mciSendString(c.c_str(), NULL, 0, NULL);
	char s[1024];
	fstream fh(p.getImage());
	while (fh.getline(s, 1024))
	{
		cout << s << endl;
	}
	system("pause");
	fh.close();
	cout << "\n";
	system("color F");
}


void PrintAtack(Atack a) {

	string nome;


	cout << "||	" << a.getNome() << "   ||\n" << endl;


	string c = "play " + a.getSound();
	mciSendString(c.c_str(), NULL, 0, NULL);


	cout << "---   " << a.getDamage() << "  ---\n" << endl;
}

void ChooseAtack(Pokemon p) {
	int indexAtack;
	vector<Atack> pokemonAtacks = p.getAtacks();

	cout << "||  Escolha um atack  ||" << endl;

	for (int i = 0; i < pokemonAtacks.size(); i++) {
		cout << i << ": " << pokemonAtacks[i].getNome() << endl;
	}

	cin >> indexAtack;

	PrintAtack(pokemonAtacks[indexAtack]);
	system("color F");
}

void ChooseDefaultPokemon(vector<Pokemon> &defaultPokemons,Player &defaultPlayer)
{
	system("CLs");
	int index_defaultPokemon;

	//Escolher um pokemon por defeito para o jogo
	string texto = "Escolha um Pokemon: \n";
	for (int i = 0; i < texto.size(); i++)
	{
		Sleep(100);
		cout << texto[i];
	}

	Sleep(700);

	for (int j = 0; j < defaultPokemons.size(); j++)
	{
		cout << j << ": " << defaultPokemons[j].getNome() << endl;
	}
	cin >> index_defaultPokemon;

	system("CLs");

	//Imprimir o pokemon escolhido por defeito
	PrintPokemonAndSound(defaultPokemons[index_defaultPokemon]);
	ChooseAtack(defaultPokemons[index_defaultPokemon]);

	defaultPlayer.addPokemon(defaultPokemons[index_defaultPokemon]);
}

void ChoosePlayer(vector<Player> &listaPlayer, Player &defaultPlayer)
{
	int indexPlayer;

	//Escolher um pokemon por defeito para o jogo
	string texto = "Escolha uma personagem: \n";
	for (int i = 0; i < texto.size(); i++)
	{
		Sleep(100);
		cout << texto[i];
	}

	Sleep(700);


	for (int j = 0; j < listaPlayer.size(); j++)
	{
		cout << j << ": " << listaPlayer[j].getNome() << endl;
	}
	cin >> indexPlayer;

	defaultPlayer = listaPlayer[indexPlayer];

	system("CLs");

	//Imprimir o pokemon escolhido por defeito
	PrintPlayerAndSound(defaultPlayer);
}

int main() {
	INTRO();

	Player defaultPlayer;

	vector<Pokemon> listaPokemons;
	vector<Player> listaPlayer;

	createPokemons(listaPokemons);
	createlistaPlayers(listaPlayer);

	ChoosePlayer(listaPlayer, defaultPlayer);
	ChooseDefaultPokemon(listaPokemons, defaultPlayer);

	_getch();

	return 0;
}