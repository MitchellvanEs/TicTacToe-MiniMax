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

	itsGameHandler = new GameHandler();
	itsGameHandler->setItsMainWindow(this);

	wxPanel *panel = new wxPanel(this, wxID_ANY);

	lblState = new wxStaticText(panel, wxID_ANY, "Press Start to begin", wxPoint(20, 20), wxSize(85, 25));

	btnPlayer1 = new wxButton(panel, wxID_ANY, "Player (O)", wxPoint(20, 40), wxSize(85, 25));
	btnPlayer2 = new wxButton(panel, wxID_ANY, "Player (X)", wxPoint(120, 40), wxSize(85, 25));

	btnPlayer1->Bind(wxEVT_BUTTON, &MainWindow::playerToggle, this);
	btnPlayer2->Bind(wxEVT_BUTTON, &MainWindow::playerToggle, this);

	btnStart = new wxButton(panel, wxID_ANY, "Start", wxPoint(20, 65), wxSize(85, 25));
	btnStart->Bind(wxEVT_BUTTON, &MainWindow::startGame, this);
	btnReset = new wxButton(panel, wxID_ANY, "Reset", wxPoint(120, 65), wxSize(85, 25));
	btnReset->Bind(wxEVT_BUTTON, &MainWindow::resetGame, this);

	for(int i = 0; i<9; i++){
		btnCells[i] = new wxButton(panel, i, "", wxPoint(75+(i%3)*25, 120+floor(i/3)*20), wxSize(25, 25));
		btnCells[i]->Bind(wxEVT_BUTTON, &MainWindow::cellSelect, this);
	}

	MainWindow::updateUI();
}

void MainWindow::playerToggle(wxCommandEvent & event){
	if(event.GetId() == btnPlayer1->GetId()){
		itsGameHandler->togglePlayerType(0);
	}else if(event.GetId() == btnPlayer2->GetId()){
		itsGameHandler->togglePlayerType(1);
	}
}

void MainWindow::cellSelect(wxCommandEvent & event) {
	itsGameHandler->setCell((int)event.GetId());
}

void MainWindow::startGame(wxCommandEvent &event) {
	itsGameHandler->startGame();
}

void MainWindow::resetGame(wxCommandEvent &event) {
	itsGameHandler->resetGame();
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

void MainWindow::updateUI(){
	btnPlayer1->SetLabel(itsGameHandler->isAI(0) ?  "AI (O)" : "Player (O)");
	btnPlayer2->SetLabel(itsGameHandler->isAI(1) ?  "AI (X)" : "Player (X)");

	switch (itsGameHandler->getState()) {
		case GameHandler::init:
			btnStart->Enable(true);
			btnPlayer1->Enable(true);
			btnPlayer2->Enable(true);
			lblState->SetLabel("Press Start to begin");
			break;
		case GameHandler::player1:
		case GameHandler::player2:
			btnStart->Enable(false);
			btnPlayer1->Enable(false);
			btnPlayer2->Enable(false);

			lblState->SetLabel(itsGameHandler->getState() == GameHandler::player1 ? "Player 1's turn" : "Player 2's turn");
			break;
		case GameHandler::player1win:
		case GameHandler::player2win:
			btnStart->Enable(false);
			btnPlayer1->Enable(false);
			btnPlayer2->Enable(false);

			lblState->SetLabel(itsGameHandler->getState() == GameHandler::player1win ? "Player 1 won" : "Player 2 won");
			break;
	}
}


