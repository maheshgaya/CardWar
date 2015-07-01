/* author: Mahesh Gaya
*  date: 03/02/15
*  description: implementation of DeckOfCards class
*	header: DeckOfCards.h, Card.h
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "DeckOfCards.h"
#include "Card.h"

using namespace std;

/*Accessor: private*/

/* method: swap(Card, Card)
*  class: DeckOfCards
*  purpose: swap cards in array
*/
void DeckOfCards::swap(Card &x, Card &y)
{
	//swap elements
	Card temp = x;
	x = y;
	y = temp;
}
/*Accessor: public*/

//Default constructor: Card()
//class: DeckOfCards
DeckOfCards::DeckOfCards()
{
	srand(time(NULL)); //random seed value
	deck = new Card[52]; //allocate the array
	
	//fill array with values
	string suits = "SHDC";
	int i=0;
	for(int r = TWO; r <= ACE; r++)
	{
		for(int s=0; s<4; s++)
		{
			deck[i].setSuit(suits[s]);
			deck[i].setRank((Rank) r);
			i++;
		}
	}
	//shuffle the deck
	shuffle();
	//cout << "Shuffled" << endl; //test
	topCardNdx = 0; //initialization
	
}

//destructor: Card()
//class: DeckOfCards
DeckOfCards::~DeckOfCards()
{
	//destructing
	cout << "destructing DeckOfCards..." << endl;
	delete[] deck; //release memory
}

/* method: shuffle()
*  class: DeckOfCards
*  purpose: shuffle deck
*/
void DeckOfCards::shuffle()
{

	for (int i= 0; i < 52; i++)
	{
		int random = rand()%52; //generate a random number
		swap(deck[i], deck[random]); //swap the value of element[i] to element[random]
	}
}
/* method: drawCard()
*  class: DeckOfCards
*  purpose: take a card from the deck
*/
Card DeckOfCards::drawCard()
{
	//display the top card from the deck and increment the pointer index
	Card topCard = *(deck+topCardNdx);
	topCardNdx++;
	return topCard;
}

/* method: drawCard(index)
*  class: DeckOfCards
*  purpose: take a card at index
*/
Card DeckOfCards::drawCard(int index)
{
	Card cardAt = *(deck+index);
	return cardAt;
}

/* method: displayArray()
*  class: DeckOfCards
*  purpose: display the whole array of deck
*/
void DeckOfCards::displayArray()
{
	for (int i=0; i < 52; i++)
	{
		cout << i << '\t' << deck[i].toString() << endl;
	}
}
