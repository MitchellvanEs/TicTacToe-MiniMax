//
// Created by Mitchell van Es on 11/07/2021.
//

#ifndef MINIMAX_H
#define MINIMAX_H

#include "GameHandler.h"

class MiniMax {
public :
	MiniMax(MiniMax* parent, int selectedCell = -1, GameHandler* gameHandler = NULL, int player = -1);

private:
	GameHandler* itsGameHandler;

	int itsDepth;
	int itsGrid[9];

    GameHandler::GridStates itsState = GameHandler::none;
	int itsSelectedCell = -1;
    bool itsTurn = false;
    int itsPlayer = 0;
    
	int itsScore = 0;
	int itsCumScore = 0;
	
	MiniMax* itsParent;
	MiniMax* itsChildren[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
};


#endif //MINIMAX_H
