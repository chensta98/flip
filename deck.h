/*
Alex Negulescu		negulescu.a@northeastern.edu
Ethan Chen			chen.eth@northeastern.edu
This file includes the deck class which creates the full deck of cards.
This file uses the d_node.h file and the card.h file to create a deck
using nodes. File also includes an overloaded operator function that
allows printing of the entire deck
*/

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

	//Destructor 
	//~deck();

	// Overload Operators
	friend ostream& operator<<(ostream& os, const deck& d);

	// Shuffle function
	void shuffle();

	node<card>* deal();

	void replace(card replace_card);
};

// Implementation

deck::deck()
{
	node<card> *current = NULL;

	// Loops through each suit
	for (int s = 3; s >= 0; s--)
	{
		// Loops through each value
		for (int v = 13; v >= 1; v--)
		{
			string suit;
			if (s == 0) suit = "spade";
			else if (s == 1) suit = "club";
			else if (s == 2) suit = "heart";
			else if (s == 3) suit = "diamond";

			// Starts from the back and creates a linked list of the deck
			firstcard = new node<card>(card(v, suit), current);
			current = firstcard;
		}
	}
}

/*deck::~deck()
{
	delete deck;
}*/

// Overloaded << operator
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

// Shuffles the deck
void deck::shuffle()
{

	/*
	// Create temporary pointers for the last card and a random card to split the deck
	node<card>* last_card = firstcard;
	node<card>* split_card;

	// Finds the last card
	while (last_card->next != NULL)
	{
		last_card = last_card->next;
	}

	for (int x = 0; x < 10; x++)
	{
		split_card = firstcard;

		// Randomly pics card in middle of deck
		int split_size = rand() % 52;

		// Gets the pointer for that card
		for (int x = 0; x < split_size; x++)
		{
			split_card = split_card->next;
		}

		// Points the last card to the first card
		last_card->next = firstcard;
		// The first card is now the split card's next pointer
		firstcard = split_card->next;
		// The split card is now the last card so set the next to NULL
		split_card->next = NULL;

		// Last card pointer is now the split card
		last_card = split_card;
	}
	*/
}

node<card>* deck::deal()
{
	node<card>* card_to_deal = firstcard;
	firstcard = firstcard->next;
	return card_to_deal;
}

void deck::replace(card replace_card)
{
	node<card>* last_card = firstcard;

	while (last_card->next != NULL)
	{
		last_card = last_card->next;
	}

	node<card> *new_last_node = new node<card>;
	new_last_node->nodeValue = replace_card;
	new_last_node->next = NULL;
	last_card->next = new_last_node;

}


#endif // Deck Class
