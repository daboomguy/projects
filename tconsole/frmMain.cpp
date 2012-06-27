#include "frmMain.h"
#include "frmConsole.h"
#include "tconsoleApp.h"

//(*InternalHeaders(frmMain)
#include <wx/string.h>
#include <wx/intl.h>
//*)

class tconsoleApp;

DECLARE_APP(tconsoleApp)

//(*IdInit(frmMain)
const long frmMain::idMenuNew = wxNewId();
const long frmMain::idClose = wxNewId();
const long frmMain::ID_STATUSBAR1 = wxNewId();
//*)

const long frmMain::ID_THREAD_STATE=wxNewId();

BEGIN_EVENT_TABLE(frmMain, wxMDIParentFrame)
	//(*EventTable(frmMain)
	//*)
  EVT_THREAD(ID_THREAD_STATE, frmMain::OnThreadState)
END_EVENT_TABLE()

frmMain::frmMain(const char *arConfigPath, wxWindow* parent,wxWindowID id)
: wxMDIParentFrame(parent, id, wxT("tconsole")/*, wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxMAXIMIZE_BOX|wxMINIMIZE_BOX*/)
{
	//(*Initialize(frmMain)
	wxMenuItem* MenuItem2;

	//Create(parent, id, _("tconsole "), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL|wxCLIP_CHILDREN, _T("id"));
	SetClientSize(wxSize(919,640));
	SetBackgroundColour(wxColour(80,80,80));
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, idMenuNew, _("New\tCtrl+N"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuItem3 = new wxMenuItem(Menu1, idClose, _("Close\tCtrl+D"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem3);
	Menu1->AppendSeparator();
	MenuItem2 = new wxMenuItem(Menu1, wxID_CLOSE, _("Quit"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem2);
	MenuBar1->Append(Menu1, _("File"));
	SetMenuBar(MenuBar1);
	StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar);

	Connect(idMenuNew,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&frmMain::OnNew);
	Connect(idClose,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&frmMain::OnMenuCloseConsoleSelected);
	Connect(wxID_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&frmMain::OnClose);
	//*)

	worker=new CWorker(this, arConfigPath);
  if (worker->Create()!=wxTHREAD_NO_ERROR) {
    wxLogError(wxT("Can't create thread!"));
  }
  else {
    if (worker->Run()!=wxTHREAD_NO_ERROR) {
      wxLogError("Can't create the thread!");
      delete worker;
      worker=NULL;
    }
  }
//  Maximize();
}

frmMain::~frmMain()
{
	//(*Destroy(frmMain)
	//*)

  if (worker->Delete()!=wxTHREAD_NO_ERROR) {
    wxLogError("Can't delete the thread!");
  }
}

void frmMain::OnClose(wxCommandEvent& event)
{
  Close();
}

void frmMain::OnNew(wxCommandEvent& event)
{
  frmConsole *con=new frmConsole(this);
  if (con)
    con->Show();
}

void frmMain::OnThreadState(wxThreadEvent& event)
{
  (event.GetInt()!=0)
  ? StatusBar->SetForegroundColour(wxColour(wxT("RED")))
  : StatusBar->SetForegroundColour(wxColour(wxT("DARK GREEN")));

  SetStatusText(event.GetString());
}

void frmMain::RegisterNode(frmConsole *frmSender, uint32 arNode)
{
  wxCriticalSectionLocker enter(wxGetApp().critsec);
  if (worker->IsRunning())
    worker->RegisterNode(frmSender, arNode);
}

void frmMain::UnregisterNode(uint32 arNode)
{
  wxCriticalSectionLocker enter(wxGetApp().critsec);
  if (worker->IsRunning())
    worker->UnregisterNode(arNode);
}

void frmMain::OnMenuCloseConsoleSelected(wxCommandEvent& event)
{
  wxMDIChildFrame *con=GetActiveChild();
  if (con) {
    con->Close();
  }
}

void frmMain::SendCommand(uint32 arNode, uint32 arInterface, MyDefaultBuffer &arCommand)
{
  wxCriticalSectionLocker enter(wxGetApp().critsec);
  if (worker->IsRunning())
    worker->SendCommand(arNode, arInterface, arCommand);
}

void frmMain::SendFile(uint32 arNode, uint32 arInterface,
                       std::string& arFullPath, std::string& arFileName)
{
  wxCriticalSectionLocker enter(wxGetApp().critsec);
  if (worker->IsRunning())
    worker->SendFile(arNode, arInterface, arFullPath, arFileName);
}


void frmMain::Resume()
{
  wxCriticalSectionLocker enter(wxGetApp().critsec);
  if (worker->IsPaused())
    worker->Resume();
}


