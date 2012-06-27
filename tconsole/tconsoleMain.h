/***************************************************************
 * Name:      tconsoleMain.h
 * Purpose:   Defines Application Frame
 * Author:    mikhail kostin (kostin.m@softcase.ru)
 * Created:   2012-06-07
 * Copyright: mikhail kostin ()
 * License:
 **************************************************************/

#ifndef TCONSOLEMAIN_H
#define TCONSOLEMAIN_H

//(*Headers(tconsoleFrame)
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

class tconsoleFrame: public wxFrame
{
    public:

        tconsoleFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~tconsoleFrame();

    private:

        //(*Handlers(tconsoleFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(tconsoleFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(tconsoleFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TCONSOLEMAIN_H
