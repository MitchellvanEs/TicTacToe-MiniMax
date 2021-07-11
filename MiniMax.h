//
// Created by Mitchell van Es on 11/07/2021.
//

#ifndef MINIMAX_H
#define MINIMAX_H

#include "GameHandler.h"

class MiniMax {
	int depth;

	int grid[9];
	GameHandler::GridStates state;
	int selectedCell = -1;

	bool isMe;

	MiniMax* child[9];
};


#endif //MINIMAX_H
