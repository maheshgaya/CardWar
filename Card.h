/* author: Mahesh Gaya
*  date: 03/02/15
*  description: Card class definition
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdio.h>
using namespace std;

enum Rank {TWO=2, THREE, FOUR, FIVE, SIX, 
	SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

class Card
{
private:
	Rank rank;
	char suit;

public:
	Card();
    	Card(Rank, char);
    	Rank getRank();
    	void setRank(Rank);
    	char getSuit();
    	void setSuit(char);
    	string toString();
};

#endif
