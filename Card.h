/*
Alex Negulescu      negulescu.a@northeastern.edu
Ethan Chen			chen.eth@northeastern.edu
This file creates the card class which creates a card using set and get functions
This class is passed values from deck.h through its constructor. This file
also includes an overloaded operator function.
*/

#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//an enumerated suit data type. Global so deck has access
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class card {
public:
	card() {}; //default constructor
	card(const int, const Suit); //constructor
	int getValue(); //will return the value
	void setValue(int val); //sets the value
	Suit getSuit(); //returns the suit
	void setSuit(const Suit); //sets the suit
	
private:
	int value; //value of card
	Suit suit; //suit of card
	

friend ostream& operator<<(ostream& out, card& c); //overloaded operator
};

//constructor
card::card(const int val, const Suit s)
{
	value = val; //sets val passed to private value
	suit = s;	 //sets s passed to private suit
}

//these are the strings that will be used when outputting card values
//First is a string of suits
const string suits[] = { "Spades", "Diamonds", "Clubs", "Hearts" };
//Second is a string of face cards
const string faces[] = { "Jack", "Queen", "King", "Ace" };

//function returns value when called
int card::getValue()
{
	return value;
}

//function sets value
void card::setValue(int val)
{
	value = val;
}

//function returns suit
Suit card::getSuit()
{
	return suit;
}

//function sets suit
void card::setSuit(const Suit s)
{
	suit = s;
}

//overloading the << operator for the card objects
ostream& operator<<(ostream& ostr, card& c)
{
	//first sets cValue to getValue return
	int cValue = c.getValue();

	//if the card is greater than 11, subtract 11 and use the faces string arr
	//and also use getSuit() to print correct suit type
	if (cValue > 11)
	{
		ostr << faces[cValue - 11] << " of " << suits[c.getSuit()];
	}
	//if the card is less than 11, value is simply the number card
	//and the suit is from getSuit()
	else
	{
		ostr << cValue << " of " << suits[c.getSuit()];
	}

	return ostr;
}

#endif
