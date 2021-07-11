//
// Created by Mitchell van Es on 11/07/2021.
//

#include "AI.h"
#include "GameHandler.h"

AI::AI(int instance) {
	instance = instance;
}

AI::~AI() {
	itsGameHandler->removeItsAI(this);
}

void AI::setItsGameHandler(GameHandler *p_GameHandler) {
	itsGameHandler = p_GameHandler;
}

int AI::generateMove() {
	int* grid = itsGameHandler->getCells();

	int i = rand() % 9;
	while(grid[i] != 0){
		i = rand() % 9;
	}

	return i;
}


