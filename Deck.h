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

#include "card.h"
#include "d_node.h"

using namespace std;

//deck class
class deck
{
public:
	deck(); //default constructor

	void shuffle(); //shuffle function
	
private:
	node<card>* cardNode; //cardNode created using d_node.h class

friend ostream& operator<<(ostream& ostr, const deck& d); //overloaded operator
};

//constructor for deck class
deck::deck()
{
	//begin with current node as NULL
	node<card> *curr = NULL;

	//loops through each suit
	for (int i = 3; i >= 0; i--)
	{
		//loops through each card in each suit
		for (int j = 14; j > 0; j--)
		{
			//creates a new node for each card that passes suit and value
			cardNode = new node<card>(card(j, static_cast<Suit>(i)), curr);

			//set current node to card just created
			curr = cardNode;
		}
	}
}

//overloaded operator function
ostream& operator<<(ostream& ostr, const deck& d)
{
	node<card>* card = d.cardNode;

	//prints list as long as card node isnt NULL
	while (card != NULL)
	{
		ostr << card->nodeValue << endl;
		card = card->next;
	}
	return ostr;
}

void deck::shuffle()
{
	node<card>* last_card = cardNode;
	node<card>* split_card = cardNode;

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

	last_card->next = cardNode;
	cardNode = split_card->next;
	split_card->next = NULL;
	split_card = cardNode;
	last_card = cardNode;
}

#endif
