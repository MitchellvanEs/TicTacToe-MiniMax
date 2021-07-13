//
// Created by Mitchell van Es on 11/07/2021.
//

#include "GameHandler.h"
#include "MainWindow.h"
#include "AI.h"

void GameHandler::setItsMainWindow(MainWindow *p_MainWindow) {
	if(p_MainWindow != NULL){
		p_MainWindow->_setItsGameHandler(this);
	}
	itsMainWindow = p_MainWindow;
}

void GameHandler::_setItsMainWindow(MainWindow *p_MainWindow) {
	if(p_MainWindow != NULL){
		p_MainWindow->__setItsGameHandler(this);
	}
	itsMainWindow = p_MainWindow;
}

void GameHandler::__setItsMainWindow(MainWindow *p_MainWindow) {
	itsMainWindow = p_MainWindow;
}

GameHandler::GameHandler() {
	GameHandler::resetGame();
}

void GameHandler::startGame() {
	if(state == init){
		state = player1;
		itsMainWindow->updateUI();

		if(itsAI[0] != NULL){
			GameHandler::setCell(itsAI[0]->generateMove());
		}
	}
}

void GameHandler::resetGame() {
	for(int i = 0; i<9; i++){
		cells[i] = 0;
	}
	state = init;

	if(itsMainWindow != NULL){
		itsMainWindow->updateGrid();
		itsMainWindow->updateUI();
	}
}


void GameHandler::togglePlayerType(int i) {
	if(itsAI[i] == NULL){
		itsAI[i] = new AI();
		itsAI[i]->setItsGameHandler(this);
	}else{
		delete itsAI[i];
	}
	itsMainWindow->updateUI();
}

bool GameHandler::isAI(int i) {
	return (itsAI[i] != NULL);
}

void GameHandler::setCell(int i) {
	if (cells[i] == 0){
		if (state == player1 || state == player2) {
			cells[i] = state == player1 ? 1 : -1;
			itsMainWindow->updateGrid();

			switch (checkGrid()) {
				case none:
					state = state == player1 ? player2 : player1;
					break;
				case full:
					state = draw;
					break;
				case p1win:
					state = player1win;
					break;
				case p2win:
					state = player2win;
					break;
			}

			itsMainWindow->updateUI();

			if(state == player1 && itsAI[0] != NULL){
				GameHandler::setCell(itsAI[0]->generateMove());
			}

			if(state == player2 && itsAI[1] != NULL){
				GameHandler::setCell(itsAI[1]->generateMove());
			}
		}
	}
}

int GameHandler::getCell(int i) {
	return cells[i];
}

int* GameHandler::getCells() {
	return cells;
}

GameHandler::GameStates GameHandler::getState() {
	return state;
}

GameHandler::GridStates GameHandler::checkGrid(int* grid) {
	if(grid == NULL){
		grid = cells;
	}

	int i;
	for(i = 0; i<9;i++){
		if(grid[i] == 0){
			break;
		}
	}
	if(i == 9){
		return full;
	}

	for(int i = 0; i < 3; i++){
		if(abs(grid[3 * i] + grid[3 * i + 1] + grid[3 * i + 2]) == 3){
			return grid[3 * i] == 1 ? p1win : p2win;
		}

		if(abs(grid[i] + grid[i + 3] + grid[i + 6]) == 3){
			return grid[i] == 1 ? p1win : p2win;
		}
	}

	if(abs(grid[0] + grid[4] + grid[8]) == 3){
		return grid[0] == 1 ? p1win : p2win;
	}
	if(abs(grid[2] + grid[4] + grid[6]) == 3){
		return grid[2] == 1  ? p1win : p2win;
	}

	return none;
}

void GameHandler::removeItsAI(AI *p_AI) {
	if(p_AI != NULL){
		for(int i = 0; i<2; i++){
			if(itsAI[i] == p_AI){
				itsAI[i] = NULL;
			}
		}
	}
}