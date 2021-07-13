//
// Created by Mitchell van Es on 11/07/2021.
//

#include "MiniMax.h"

MiniMax::MiniMax(GameHandler* gameHandler, MiniMax* parent, int selectedCell) {
	itsGameHandler = gameHandler;
	itsParent = parent;

	if(parent != NULL){
		itsDepth = itsParent->itsDepth + 1;
		itsSelectedCell = selectedCell;

		for(int i = 0; i<9; i++) {
			itsGrid[i] = itsParent->itsGrid[i];
		}

		itsGrid[itsSelectedCell] = 1;

		myTurn = !parent->myTurn;
	}else{
		itsDepth = 0;

		for(int i = 0; i<9; i++) {
			itsGrid[i] = itsGameHandler->getCell(i);
		}
	}

	itsState = itsGameHandler->checkGrid(itsGrid);

	switch (itsState) {
		case GameHandler::none:
		case GameHandler::full:
			itsScore = 0;
			break;
		case GameHandler::p1win:
		case GameHandler::p2win:
			if(myTurn){
				itsScore = 1*(10-itsDepth);
			}else{
				itsScore = -1*(10-itsDepth);
			}
			break;
	}

	if(itsDepth < 1){
		for(int i = 0; i<9; i++){
			if(itsGrid[i] == 0 && itsScore == 0) {
				itsChildren[i] = new MiniMax(itsGameHandler, this, i);
			}
		}
	}

	if(parent != NULL){
		parent->itsCumScore += itsScore + itsCumScore;
	}

}
