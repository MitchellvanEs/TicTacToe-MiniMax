//
// Created by Mitchell van Es on 10/07/2021.
//

#include "MainClass.h"
#include "MainWindow.h"
#include "GameHandler.h"

MainClass::MainClass(){
	std::cout << "instatiate\n";
}

MainClass::~MainClass(){
	std::cout << "destroy\n";
}
bool MainClass::OnInit() {
	std::cout << "Create frame\n";
	p_MainWindow = new MainWindow("TicTacToe", wxPoint(1400, 50), wxSize(225, 250) );
	p_MainWindow->Show( true );
	return true;
}