//
// Created by Mitchell van Es on 11/07/2021.
//

#include "MiniMax.h"

MiniMax::MiniMax(MiniMax* parent, int selectedCell, GameHandler* gameHandler, int player) {
	itsParent = parent;

	if(itsParent != NULL){
        itsGameHandler = itsParent->itsGameHandler;
		itsDepth = itsParent->itsDepth + 1;
		itsSelectedCell = selectedCell;
        itsPlayer = itsParent->itsPlayer;
        
		for(int i = 0; i<9; i++) {
			itsGrid[i] = itsParent->itsGrid[i];
		}

		itsGrid[itsSelectedCell] = player ? -1 : 1;

        itsTurn = !itsParent->itsTurn;
    }else{      
        itsGameHandler = gameHandler;
        itsDepth = 0;
        itsPlayer = player;
        
        for(int i = 0; i<9; i++) {
            itsGrid[i] = itsGameHandler->getCell(i);
        }

        itsTurn = true;
    }
    
    itsState = itsGameHandler->checkGrid(itsGrid);;
    
	if(itsDepth < 1){
		for(int i = 0; i<9; i++){
			if(itsGrid[i] == 0) {
				itsChildren[i] = new MiniMax(this, i);
			}
		}
	}
}
