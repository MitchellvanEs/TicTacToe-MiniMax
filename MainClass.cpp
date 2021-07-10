//
// Created by Mitchell van Es on 10/07/2021.
//

#include "MainClass.h"


MainClass::MainClass(){
	std::cout << "instatiate\n";
}

MainClass::~MainClass(){
	std::cout << "destroy\n";
}
bool MainClass::OnInit() {
	std::cout << "Create frame\n";
	p_MainWindow = new MainWindow("TicTacToe", wxPoint(50, 50), wxSize(450, 340) );
	p_MainWindow->Show( true );
	return true;
}