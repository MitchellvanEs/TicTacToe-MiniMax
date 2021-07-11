//
// Created by Mitchell van Es on 10/07/2021.
//

#include "MainWindow.h"
#include "GameHandler.h"

void MainWindow::setItsGameHandler(GameHandler *p_GameHandler) {
	if(p_GameHandler != NULL){
		p_GameHandler->_setItsMainWindow(this);
	}
	itsGameHandler = p_GameHandler;
}

void MainWindow::_setItsGameHandler(GameHandler *p_GameHandler) {
	if(p_GameHandler != NULL){
		p_GameHandler->__setItsMainWindow(this);
	}
	itsGameHandler = p_GameHandler;
}

void MainWindow::__setItsGameHandler(GameHandler *p_GameHandler) {
	itsGameHandler = p_GameHandler;
}

GameHandler *MainWindow::getItsGameHandler() {
	return itsGameHandler;
}

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame(NULL, wxID_ANY, title, pos, size){

	wxPanel *panel = new wxPanel(this, wxID_ANY);

	lblState = new wxStaticText(panel, wxID_ANY, "Press Start to begin", wxPoint(20, 20), wxSize(85, 25));

	btnPlayer1 = new wxButton(panel, wxID_ANY, "Player", wxPoint(20, 40), wxSize(85, 25));
	btnPlayer2 = new wxButton(panel, wxID_ANY, "Player", wxPoint(120, 40), wxSize(85, 25));

	btnPlayer1->Bind(wxEVT_BUTTON, &MainWindow::playerToggle, this);
	btnPlayer2->Bind(wxEVT_BUTTON, &MainWindow::playerToggle, this);

	btnStart = new wxButton(panel, wxID_ANY, "Start", wxPoint(20, 65), wxSize(85, 25));
	btnRestart = new wxButton(panel, wxID_ANY, "Restart", wxPoint(120, 65), wxSize(85, 25));

	for(int i = 0; i<9; i++){
		btnCells[i] = new wxButton(panel, i, "", wxPoint(75+(i%3)*25, 120+floor(i/3)*20), wxSize(25, 25));
		btnCells[i]->Bind(wxEVT_BUTTON, &MainWindow::cellSelect, this);
	}
}

void MainWindow::playerToggle(wxCommandEvent & event){
	if(event.GetId() == btnPlayer1->GetId()){

	}else if(event.GetId() == btnPlayer2->GetId()){

	}
}

void MainWindow::cellSelect(wxCommandEvent & event) {
	itsGameHandler->setCell((int)event.GetId());
}

void MainWindow::updateGrid() {
	for(int i = 0; i < 9; i++){
		switch(itsGameHandler->getCell(i)){
			case -1:
				btnCells[i]->SetLabel("X");
				break;
			case 0:
				btnCells[i]->SetLabel("");
				break;
			case 1:
				btnCells[i]->SetLabel("O");
				break;
		}
	}
}
