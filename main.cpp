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

void playGame()
{
	cout << "FLIP GAME! " << endl;

	// Create a deck for the game
	deck game_deck = deck();

	// running bool to continue game or stop
	bool running = true;

	// store user score
	int score = 0;

	int cards_left = 24;

	game_deck.shuffle();

	node<card>* dealt_card = new node<card>(game_deck.deal(), NULL);
	node<card>* current = dealt_card;
	
	for (int x = 0; x < 22; x++)
	{
		node<card>* new_node = new node<card>(game_deck.deal(), NULL);
		current->next = new_node;
		current = current->next;
	}

	cout << "Printing top 24 cards: " << endl;
	node<card>* print_card = dealt_card;
	while (print_card != NULL)
	{
		cout << print_card->nodeValue << endl;
		print_card = print_card->next;
	}

	cout << "Printing rest of deck: " << endl;
	cout << game_deck;


	while (running)
	{
		cout << "Your score is: " << score << endl;
		cout << "Cards Remaining: " << cards_left << endl;

		cout << "Please pick number between 1 and " << cards_left << ": ";
		int choice;
		cin >> choice;

		node<card>* picked_node = dealt_card;
		for (int x = 1; x < choice; x++)
		{
			picked_node = picked_node->next;
		}

		card picked_card = picked_node->nodeValue;

		cout << "Your card is: " << picked_card << endl;
		cards_left--;

		if (picked_card.getValue() == 2 || picked_card.getValue() == 3 || picked_card.getValue() == 4 || picked_card.getValue() == 5 || picked_card.getValue() == 6)
		{
			score = 0;
		}
		else if (picked_card.getValue() == 8 || picked_card.getValue() == 9 || picked_card.getValue() == 10)
		{
			score = score;
		}
		else if (picked_card.getValue() == 13 || picked_card.getValue() == 12 || picked_card.getValue() == 11)
		{
			score = score + 5;
		}
		else if (picked_card.getValue() == 7)
		{
			score = score / 2;
		}
		else if (picked_card.getValue() == 1)
		{
			score = score + 10;
		}

		if (picked_card.getSuit() == "heart")
		{
			score++;
		}

		cout << "Your score is: " << score << endl;

		cout << "Would you like to keep playing (1 = yes, 0 = no): ";
		int playing;
		cin >> playing;
		if (playing == 0 || cards_left == 0)
		{
			running = false;
		}
		else if (playing == 1)
		{
			running = true;
		}
		else
		{
			cout << "Please pick valid option" << endl;
		}
	}
	
	cout << "FINAL SCORE: " << score << endl;
	
}

int main()
{
	playGame();

	/*
	srand(time(NULL));
	cout << "Flip Game!" << endl;

	cout << "DECK TEST" << endl;
	deck test_deck = deck();

	cout << test_deck << endl;

	cout << "SHUFFLING DECK" << endl;

	test_deck.shuffle();

	cout << test_deck;

	card card_to_deal = test_deck.deal();
	cout << "Dealt Card: ";
	cout << card_to_deal << endl;

	test_deck.replace(card(1, "spade"));

	cout << "Testing Replace function" << endl;
	cout << test_deck;
	*/
}


