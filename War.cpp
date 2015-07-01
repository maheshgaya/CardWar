/*
* author: Mahesh Gaya
* date: 03/25/15
* description (PP5-modified): war of cards
*/

/*
	pseudocode:
		ask user if he wants to play
		if yes then game is ON
		if cards of each player are different, then BATTLE
		else if cards of each player are the same, then WAR, show next cards in each decks
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "War.h"
#include "Game.h"
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

//all the functions

/* keepScore
*  input: card for computer, card for player, score, index(to keep track of card in deck), deck
*  class: War
*  purpose: calculate score and store it to score
*/
void War::keepScore(Card &computerCard, Card &playCard ,Score* gameScore, int* index, DeckOfCards &shuffledDeck)
{
	//score +2 if wins
	//score -1 if loses (negative marking)
	//game if draws
	int i = *index;
	
	if(computerCard.getRank() > playCard.getRank())
	{
		cout << "It's a battle" << endl;
		gameScore->computer += 2;
		gameScore->player--;
	}
	else if(computerCard.getRank() < playCard.getRank())
	{
		cout << "It's a battle" << endl;
		gameScore->player += 2;
		gameScore->computer--;
	}
	else if(computerCard.getRank() == playCard.getRank())
	{
		cout << "It's a WAR!" << endl;
		(*index)++; //increment pointer index
		game(shuffledDeck, index, gameScore); //rematch
	}
	
}

/* game
*  input: deck, index(for keeping track of top card in deck), score
*  class: War
*  purpose: this is where the actual game starts
*/

void War::game(DeckOfCards &shDeck, int* index, Score* gScore) //shDeck means shuffled deck
{
	//cout << "game function" << endl;//test
	int i = *index;
	cout << "----------------------" << endl;
	Card compCard = shDeck.drawCard(i);
	Card playerCard = shDeck.drawCard(i+26);
	cout << "Computer got " << compCard.toString() << endl; //first deck
	cout << "You got " << playerCard.toString() << endl; //second deck
	keepScore(compCard, playerCard, gScore, index, shDeck); //keep track of score
	
}


/* play function
*  input: none
*  class: War
*  purpose: This is where the program starts. user can start playing the game
*/
void War::play()
{
	DeckOfCards cardDeck; //declare a deck
	char key;
	//cardDeck.displayArray(); //test
	//welcoming message
	cout << "Welcome to War of Cards" << endl;

	//ask user if he wants to play game of war
	cout << "Would you like to play? Press y to play" << endl;
	cin >> key;
	
	int count = 0; //initialize count
	
	//initialize both scores to zero
	Score score;
	score.computer = 0;
	score.player = 0; 

	//if key is yes or 'y' or 'Y'
	while (key == 'y' || key =='Y')
	{
		//cout << "key" << endl; //test
		game(cardDeck, &count, &score); //play game, first deck and second deck
		
		//print scores
		cout << "----------------------" << endl;
		cout << "Computer score: " << score.computer << endl;
		cout << "Your score: " << score.player << endl;
		cout << "----------------------" << endl;		
			
		count++; //increment count
		if (count == 26)
		{
			cardDeck.shuffle(); //shuffle deck when deck is over	
			//cardDeck.displayArray(); //test
			count = 0; //reinitialize count
		}
		
		//final score is 100
		if (score.computer >= 100 || score.player >= 100)
		{	
			break; //break of while loop and print results
		}
		//ask again if the player wants to play more
		cout << "Would you like to play? Press y to play" << endl;
		cin >> key;
		
	}
	
	//when done, print results
	cout << "Computer got a score of " << score.computer << endl;
	cout << "You got a score of " << score.player << endl;
	if (score.computer > score.player)
	{
		cout << "Oops! Computer WON! You LOST!" << endl;
	}
	else if (score.computer < score.player)
	{
		cout << "Great! You WON! Computer LOST!" << endl;
	}
	else if (score.computer == score.player)
	{
		cout << "Kinda nice! It's a tie!" << endl;
	}

}

/* destructor
*  class: War
*/
War::~War()
{
	cout << "destructing war..." << endl;
}
