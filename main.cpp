/*
* author: Mahesh Gaya
* date: 03/23/15
* description: main file for card game program
* 		makes use of inheritance, class, virtual member, pointers, pass by reference
*/

#include <iostream>
#include "Game.h"
#include "War.h"
#include "HighLow.h"
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

int main()
{
	int response = 0; //initialization
	Game *myGame;

	while(response != 3)
	{
		cout << "Press 1 to play War" << endl;
		cout << "Press 2 to play HighLow" << endl;
		cout << "Press 3 to quit" << endl;
		cin >> response; //user response
		
		switch (response)
		{
		case 1: 
			myGame = new War(); //game of War
			break;
		case 2:
			myGame = new HighLow(); //high low Game
			break;
		default:
			return 0;
		}
		myGame->play();
		delete myGame;

	}

}
