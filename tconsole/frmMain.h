#ifndef FRMMAIN_H
#define FRMMAIN_H

//(*InternalHeaders(frmMain)
//*)
#include "wx/wxprec.h"
#include <wx/wx.h>
#include <wx/mdi.h>
#include "CWorker.h"

class frmMain: public wxMDIParentFrame
{
	public:

		frmMain(const char *arConfigPath, wxWindow* parent=NULL,wxWindowID id=wxID_ANY);
		virtual ~frmMain();

		//(*Declarations(frmMain)
		wxMenuItem* MenuItem1;
		wxMenu* Menu1;
		wxMenuItem* MenuItem3;
		wxMenuBar* MenuBar1;
		wxStatusBar* StatusBar;
		//*)

    void ToStatusBar(wxString arText);

    void OnThreadState(wxThreadEvent& event);
		static const long ID_THREAD_STATE;

		void RegisterNode(frmConsole *frmSender, uint32 arNode);
		void UnregisterNode(uint32 arNode);
		void SendCommand(uint32 arNode, uint32 arInterface, MyDefaultBuffer &arCommand);
    void SendFile(uint32 arNode, uint32 arInterface,
                  std::string& arFullPath, std::string& arFileName);

    void Resume();

	protected:

		//(*Identifiers(frmMain)
		static const long idMenuNew;
		static const long idClose;
		static const long ID_STATUSBAR1;
		//*)

  public:
		CWorker *worker;
	private:

		//(*Handlers(frmMain)
		void OnClose(wxCommandEvent& event);
		void OnNew(wxCommandEvent& event);
		void OnMenuCloseConsoleSelected(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
