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
}