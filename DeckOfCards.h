/* author: Mahesh Gaya
*  date: 03/02/15
*  description: Deck class definition
*/

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class DeckOfCards
{
private:
	Card *deck;
	int topCardNdx;
	void swap(Card &, Card &);

public:
	DeckOfCards();
	~DeckOfCards();
	void shuffle();
	Card drawCard();
	Card drawCard(int);
	void displayArray();
};

#endif
