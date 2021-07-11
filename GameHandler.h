//
// Created by Mitchell van Es on 11/07/2021.
//

#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow;
class AI;

class GameHandler {
public:
	enum GameStates {init, player1, player2, player1win, player2win, draw};
	enum GridStates {none, full, p1win, p2win};
	GameHandler();

	void setItsMainWindow(MainWindow* p_MainWindow);
	void _setItsMainWindow(MainWindow* p_MainWindow);
	void __setItsMainWindow(MainWindow* p_MainWindow);

	void removeItsAI(AI* p_AI);

	void setCell(int i);
	int getCell(int i);
	GridStates checkGrid();
	int* getCells();

	void startGame();
	void resetGame();
	void togglePlayerType(int i);
	bool isAI(int i);

	GameStates getState();

private:
	MainWindow* itsMainWindow = NULL;
	AI* itsAI[2] = {NULL, NULL};

	int cells[9];
	GameStates state;
};


#endif //GAMEHANDLER_H
