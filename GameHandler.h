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
	enum States {init, player1, player2, player1win, player2win};
	GameHandler();

	void setItsMainWindow(MainWindow* p_MainWindow);
	void _setItsMainWindow(MainWindow* p_MainWindow);
	void __setItsMainWindow(MainWindow* p_MainWindow);

	void removeItsAI(AI* p_AI);

	MainWindow* getItsMainWindow();

	void setCell(int i);
	int getCell(int i);
	bool checkGrid();

	void startGame();
	void resetGame();
	void togglePlayerType(int i);
	bool isAI(int i);

	States getState();

private:
	MainWindow* itsMainWindow = NULL;
	AI* itsAI[2] = {NULL, NULL};

	int cells[9];
	States state;
};


#endif //GAMEHANDLER_H
