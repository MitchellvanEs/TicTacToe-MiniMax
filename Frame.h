//
// Created by Mitchell van Es on 10/07/2021.
//

#ifndef FRAME_H
#define FRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class Frame : public wxFrame {
public:
    Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
};

#endif //FRAME_H
