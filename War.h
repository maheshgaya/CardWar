/*
* author: Mahesh Gaya
* date: 03/23/15
* description: War Class
*/

#ifndef WAR_H
#define WAR_H

#include <iostream>
#include "Game.h"
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

//structure for score
struct Score
{
	//keep scores
	int computer;
	int player;
};

class War: public Game
{
private:	
	void keepScore(Card&, Card& ,Score*, int*, DeckOfCards&);
public:
	void play();
	void game(DeckOfCards &, int*, Score*);
	~War();
};
#endif
