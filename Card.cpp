/* author: Mahesh Gaya
*  date: 03/02/15
*  description: implementation of Card class
*	header: Card.h
*/

#include <iostream>
#include "Card.h"
using namespace std;

/*Accessor: public*/

//Default constructor: Card()
//class: Card
Card::Card()
{
	//do nothing
}

//User-defined constructor: Card(Rank, char)
//class: Card
Card::Card(Rank cardRank, char cardSuit)
{
	rank = cardRank;
	suit = cardSuit;
}

/* method: getRank()
*  class: Card
*  purpose: return value of rank
*/
Rank Card::getRank()	
{
	return rank;
}

/* method: setRank()
*  class: Card
*  purpose: set value of rank
*/
void Card::setRank(Rank newRank)
{
	rank = newRank;
}

/* method: getSuit()
*  class: Card
*  purpose: return value of suit
*/
char Card::getSuit()
{
	return suit;
}

/* method: setSuit()
*  class: Card
*  purpose: set value of suit
*/
void Card::setSuit(char newSuit)
{	
	suit = newSuit;
}

/* method: toString()
*  class: Card
*  purpose: convert Rank to string and return the result(Rank, suit)
*/
string Card::toString()
{
	string result = "xx"; //allocate space for a 2-character string
	char container[1];
	sprintf(container, "%d", rank);
	if (rank == TEN)
	{
		container[0] = 'T';
	}
	else if (rank == JACK)
	{
		container[0] = 'J';
	}
	else if (rank == QUEEN)
	{
		container[0] = 'Q';
	}
	else if (rank == KING)
	{
		container[0] = 'K';
	}
	else if (rank == ACE)
	{
		container[0] = 'A';
	}
	//result
	result[0] = container[0];
	result[1] = suit;
		
	return result;
}
