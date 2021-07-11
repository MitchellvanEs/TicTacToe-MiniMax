//
// Created by Mitchell van Es on 10/07/2021.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class GameHandler;

class MainWindow : public wxFrame {
public:
	MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);

	void setItsGameHandler(GameHandler* p_GameHandler);
	void _setItsGameHandler(GameHandler* p_GameHandler);
	void __setItsGameHandler(GameHandler* p_GameHandler);
	GameHandler* getItsGameHandler();

	void updateGrid();

private:
	GameHandler* itsGameHandler = NULL;

	wxStaticText* lblState;
	wxButton* btnPlayer1;
	wxButton* btnPlayer2;
	wxButton* btnStart;
	wxButton* btnRestart;
	wxButton* btnCells[9];

	void playerToggle(wxCommandEvent & event);
	void cellSelect(wxCommandEvent &event);
};

#endif //MAINWINDOW_H
