//
// Created by Mitchell van Es on 10/07/2021.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainClass : public wxApp{

public:
	MainClass();
	~MainClass();
	virtual bool OnInit();
private:

protected:

};


#endif //MAINWINDOW_H
