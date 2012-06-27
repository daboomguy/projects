/***************************************************************
 * Name:      tconsoleApp.cpp
 * Purpose:   Code for Application Class
 * Author:    mikhail kostin (kostin.m@softcase.ru)
 * Created:   2012-06-07
 * Copyright: mikhail kostin ()
 * License:
 **************************************************************/

#include "tconsoleApp.h"
#include "frmMain.h"

//(*AppHeaders
#include <wx/image.h>
//*)


IMPLEMENT_APP(tconsoleApp);

bool tconsoleApp::OnInit()
{
  if (wxApp::argc!=2) {
    wxMessageBox("Usage: ./tconsole CONFIG_PATH");
    return false;
  }
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    //*)

  wxGetApp();
  frmMain *Main=new frmMain((wxApp::argv[1].mb_str(wxConvUTF8))/*"/home/mikhail/Programming/TSERVER/tconsole/bin/Debug/config.xml"*/);
  if (wxsOK) {
    Main->Show();
    SetTopWindow(Main);
  }

  return wxsOK;
}
