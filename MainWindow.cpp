//
// Created by Mitchell van Es on 10/07/2021.
//

#include "MainWindow.h"

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame(NULL, wxID_ANY, title, pos, size){

	wxPanel *panel = new wxPanel(this, wxID_ANY);

	btnPlayer1 = new wxButton(panel, wxID_ANY, "Player 1", wxPoint(20, 20));
	btnPlayer2 = new wxButton(panel, wxID_ANY, "Player 2", wxPoint(120, 20));

	btnPlayer1->Bind(wxEVT_BUTTON, &MainWindow::playerToggle, this);
	btnPlayer2->Bind(wxEVT_BUTTON, &MainWindow::playerToggle, this);
}

void MainWindow::playerToggle(wxCommandEvent & event){
	if(event.GetId() == btnPlayer1->GetId()){

	}else if(event.GetId() == btnPlayer2->GetId()){

	}
}
