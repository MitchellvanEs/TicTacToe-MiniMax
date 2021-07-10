//
// Created by Mitchell van Es on 10/07/2021.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow : public wxFrame {
public:
	MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	wxButton* btnPlayer1;
	wxButton* btnPlayer2;

	void playerToggle(wxCommandEvent & event);
};

#endif //MAINWINDOW_H
