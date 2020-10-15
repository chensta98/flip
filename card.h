#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;


// Card Class Declaration
class card
{
private:
	// Value of the card 1-13 (Ace = 1, King = 13)
	int value;
	// Suit of the card (spade, club, heart, diamond)
	string suit;

public:
	// Defualt constructor (ace of spades)
	card()
	{
		value = 1;
		suit = "spade";
	}
	// Constructor: passed value and suit
	card(int v, string s)
	{
		value = v;
		suit = s;
	}
	
	// Setter Functions
	void setValue(int v);
	void setSuit(string s);

	// Getter Functions
	int getValue();
	string getSuit();

	// Overload Operators
	friend ostream& operator<<(ostream& os, const card& c);
};

// Card Class implementation

void card::setValue(int v)
{
	value = v;
}

void card::setSuit(string s)
{
	suit = s;
}

int card::getValue()
{
	return value;
}

string card::getSuit()
{
	return suit;
}

// Print card (replaces value with face if facecard)
ostream& operator<<(ostream& os, const card& c)
{
	string card_out;
	if (c.value == 1)
	{
		card_out = "Ace of " + c.suit + "'s";
	}
	else if (c.value == 11)
	{
		card_out = "Jack of " + c.suit + "'s";
	}
	else if (c.value == 12)
	{
		card_out = "Queen of " + c.suit + "'s";
	}
	else if (c.value == 13)
	{
		card_out = "King of " + c.suit + "'s";
	}
	else
	{
		card_out = to_string(c.value) + " of " + c.suit + "'s";
	}

	os << card_out;

	return os;
}

#endif // card class