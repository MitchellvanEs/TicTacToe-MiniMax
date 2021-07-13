//
// Created by Mitchell van Es on 11/07/2021.
//

#ifndef MINIMAX_H
#define MINIMAX_H

#include "GameHandler.h"

class MiniMax {
public :
	MiniMax(GameHandler* gameHandler, MiniMax* parent, int selectedCell = -1);


	GameHandler* itsGameHandler;

	int itsDepth;

	int itsGrid[9];


	GameHandler::GridStates itsState;
	int itsSelectedCell = -1;
	int itsScore = 0;
	int itsCumScore = 0;
	bool myTurn = false;

	MiniMax* itsParent;
	MiniMax* itsChildren[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
};


#endif //MINIMAX_H
