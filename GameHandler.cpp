//
// Created by Mitchell van Es on 11/07/2021.
//

#include "GameHandler.h"
#include "MainWindow.h"

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
	for(int i = 0; i<9; i++){
		cells[i] = 0;
	}
}

void GameHandler::setCell(int i) {
	cells[i] = 1;
	itsMainWindow->updateGrid();
}

int GameHandler::getCell(int i) {
	return cells[i];
}