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

class GameHandler {
public:
	GameHandler();

	void setItsMainWindow(MainWindow* p_MainWindow);
	void _setItsMainWindow(MainWindow* p_MainWindow);
	void __setItsMainWindow(MainWindow* p_MainWindow);
	MainWindow* getItsMainWindow();

	void setCell(int i);
	int getCell(int i);

private:
	MainWindow* itsMainWindow = NULL;

	int cells[9];


};


#endif //GAMEHANDLER_H
