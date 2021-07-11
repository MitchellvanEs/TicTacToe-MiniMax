//
// Created by Mitchell van Es on 10/07/2021.
//

#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow;
class GameHandler;

class MainClass : public wxApp{

public:
	MainClass();
	~MainClass();
	virtual bool OnInit();

private:
	MainWindow *p_MainWindow;
protected:

};


#endif //MAINCLASS_H
