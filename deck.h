#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "node.h"
#include "card.h"

using namespace std;

class deck
{
private:
	node<card>* firstcard;

public:
	// Default contructor
	deck();

	// Overload Operators
	friend ostream& operator<<(ostream& os, const deck& d);

	// Shuffle function
	void shuffle();

	// Print first card
	void printFirstCard();
};

// Implementation

deck::deck()
{
	node<card> *current = NULL;

	for (int s = 3; s >= 0; s--)
	{
		for (int v = 13; v >= 1; v--)
		{
			string suit;
			if (s == 0) suit = "spade";
			else if (s == 1) suit = "club";
			else if (s == 2) suit = "heart";
			else if (s == 3) suit = "diamond";

			firstcard = new node<card>(card(v, suit), current);
			current = firstcard;
		}
	}
}

ostream& operator<<(ostream& os, const deck& d)
{
	node<card>* current = d.firstcard;

	while (current != NULL)
	{
		os << current->nodeValue << endl;
		current = current->next;
	}
	
	return os;
}

void deck::shuffle()
{
	node<card>* last_card = firstcard;
	node<card>* split_card = firstcard;

	while (last_card->next != NULL)
	{
		last_card = last_card->next;
	}

	int split_size = rand() % 52;
	cout << split_size << endl;

	for (int x = 0; x < split_size; x++)
	{
		split_card = split_card->next;
	}

	cout << "SPLIT CARD: ";
	cout << split_card->nodeValue << endl;

	last_card->next = firstcard;
	firstcard = split_card->next;
	split_card->next = NULL;
	split_card = firstcard;
	last_card = firstcard;
}


void deck::printFirstCard()
{
	cout << firstcard->nodeValue << endl;
}

#endif // Deck Class
