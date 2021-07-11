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

MainWindow *GameHandler::getItsMainWindow() {
	return itsMainWindow;
}

GameHandler::GameHandler() {
	GameHandler::resetGame();
}

void GameHandler::startGame() {
	if(state == init){
		state = player1;
		itsMainWindow->updateUI();
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
		itsAI[i] = new AI(i);
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
	if(state == player1 || state == player2){
		cells[i] = state == player1 ? 1 : -1;
		itsMainWindow->updateGrid();

		if(checkGrid()){
			state = state == player1 ? player1win : player2win;
		}else {
			state = state == player1 ? player2 : player1;
		}
		itsMainWindow->updateUI();
	}
}

int GameHandler::getCell(int i) {
	return cells[i];
}

GameHandler::States GameHandler::getState() {
	return state;
}

bool GameHandler::checkGrid() {
	for(int i = 0; i < 3; i++){
		if(abs(cells[3 * i] + cells[3 * i + 1] + cells[3 * i + 2]) == 3){
			return true;
		}

		if(abs(cells[i] + cells[i + 3] + cells[i + 6]) == 3){
			return true;
		}
	}

	if(abs(cells[0] + cells[4] + cells[8]) == 3){
		return true;
	}
	if(abs(cells[2] + cells[4] + cells[6]) == 3){
		return true;
	}

	return false;
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