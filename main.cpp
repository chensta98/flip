/*
Alex Negulescu      negulescu.a@northeastern.edu
Ethan Chen			chen.eth@northeastern.edu
This is the main file where the game is played
*/


#include <iostream>
#include <time.h>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
	srand(time(NULL));
	cout << "Flip Game!" << endl;

	cout << "DECK TEST" << endl;
	deck test_deck = deck();

	cout << test_deck << endl;

	cout << "SHUFFLING DECK" << endl;

	test_deck.shuffle();

	cout << test_deck;

	node<card>*card_to_deal = test_deck.deal();
	cout << "Dealt Card: ";
	cout << card_to_deal->nodeValue << endl;

	test_deck.replace(card(1, "spade"));

	cout << "Testing Replace function" << endl;
	cout << test_deck;
}
