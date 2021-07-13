//
// Created by Mitchell van Es on 11/07/2021.
//

#include "AI.h"
#include "GameHandler.h"

AI::AI() {

}

AI::~AI() {
	itsGameHandler->removeItsAI(this);
}

void AI::setItsGameHandler(GameHandler *p_GameHandler) {
	itsGameHandler = p_GameHandler;
}

int AI::generateMove() {
	minimaxHead = new MiniMax(itsGameHandler, NULL);

	int randomMove = rand() % 9;
	while(minimaxHead->itsChildren[randomMove] == NULL){
		randomMove = rand() % 9;
	}
	MiniMax* child = minimaxHead->itsChildren[randomMove];
	int bestScore = child->itsCumScore;
	int nextMove = child->itsSelectedCell;

	for(int i=0; i<9; i++){
		if(minimaxHead->itsChildren[i] != NULL) {
			child = minimaxHead->itsChildren[i];
			if(child->itsScore == 1){
				nextMove = child->itsSelectedCell;
				break;
			}
			if (child->itsCumScore > bestScore) {
				nextMove = child->itsSelectedCell;
				bestScore = child->itsCumScore;
			} else if (child->itsCumScore == bestScore) {
				if (((float) rand()) / (float) RAND_MAX < 0.4) {
					nextMove = child->itsSelectedCell;
				}
			}
		}
	}

	//debugMiniMax(minimaxHead);

	return nextMove;
}

void AI::debugMiniMax(MiniMax *child) {
	if(child != NULL){
		std::cout << "MiniMax " << child->itsDepth << "." << child->itsSelectedCell << "\n";

		std::cout << child->itsState << " " << child->itsScore << " " << child->itsCumScore;

		std::cout << "\n\n";


		for (int i = 0; i < 9 ; i++) {
			debugMiniMax(child->itsChildren[i]);
		}
	}

}


