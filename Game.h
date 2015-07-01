/*
* author: Mahesh Gaya
* date: 03/23/15
* description: base class: Game
*/
#ifndef GAME_H
#define GAME_H

class Game
{
public:
	virtual void play()=0; //play method to override by child objects
	virtual ~Game() {};

};

#endif
