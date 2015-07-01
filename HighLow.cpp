/* author: Mahesh Gaya
*  date: 03/02/15
*  description: high and low guess game
	contains the main function for the guessing game
*	header: Card.h, DeckOfCards.h, Game.h, HighLow.h
*
*/

/*
* draw a card
* ask the user to guess if the next card is low or high
* reveal the card
* continue from beginning
* if wrong guess: score -1
* if right guess: score +1
*/

#include <iostream>
#include <stdlib.h>
#include "DeckOfCards.h"
#include "Card.h"
#include "Game.h"
#include "HighLow.h"
 
/* play()
*  input: none
*  class: HighLow
*  purpose: play the game of High and Low
*/
void HighLow::play()
{
	
	DeckOfCards cardDeck; //declare card deck
	//welcome message
	cout << "Welcome to high or low card guess game" << endl;	

	//Ask if the user wants to play
	char userPlay, guess;
	int score = 0; //initialize score
	int numGame = 0; //initialize number of game
	cout << "========================================================" << endl;
	cout << "Would you like to take the challenge? (y)es or (n)o: ";
	cin >> userPlay;
	
	
	Card firstCard = cardDeck.drawCard();//Draw first card 
	Card secondCard = cardDeck.drawCard(); //Draw second card

	

	while (userPlay == 'y' || userPlay == 'Y')
	{	
		//increment numGame
		numGame++;
		cout << "--------------------------------------------------------" << endl;
		cout << "Game #" << numGame << endl;		
		cout << "The card drawn is: " << firstCard.toString() << endl;
		cout << "Can you guess if the next card is (h)igher or (l)ower?: "; //allow user to guess
		cin >> guess;
		cout << "--------------------------------------------------------" << endl;
		
		//keep score
		if (guess=='h' || guess=='H')
		{
			if (secondCard.getRank() > firstCard.getRank())
			{
				cout << "It's higher! You are right" << endl;
				score++; //score +1 if right
			}
			else
			{
				cout << "It's lower! Sorry! You are wrong" << endl;
				score--; //score -1 if wrong
			}
		}
		else if (guess=='l' || guess=='L')
		{
			if (secondCard.getRank() < firstCard.getRank())
			{
				cout << "It's lower! You are right" << endl;
				score++; //score +1 if right
			}
			else
			{
				cout << "It's higher! Sorry! You are wrong" << endl;
				score--; //score -1 if wrong
			}
		}
		
		cout << "Your score is: " << score << endl; //output score		
		cout << "========================================================" << endl;
		//switch cards: secondCard goes to firstCard
		//secondCard is next card on top of deck
		firstCard = secondCard;
		secondCard = cardDeck.drawCard();
		
		//ask if user wants to play again
		cout << "Would you like to guess the next card? (y)es or (n)o: ";
		cin >> userPlay;

	}

	cout << "********************************************************" << endl;
	cout << "Your final score is: " << score << endl; //final score
	cout << "Number of games played: " << numGame << endl;
	cout << "********************************************************" << endl;

}

/* Destructor
*  class: HighLow
*/
HighLow::~HighLow()
{
	cout << "destructing HighLow..." << endl;
}
