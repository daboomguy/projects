#include "frmConsole.h"
#include <wx/msgdlg.h>
#include <wx/datetime.h>
#include "frmMain.h"
#include "tconsoleApp.h"
//(*InternalHeaders(frmConsole)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <fstream>
#include <sstream>
#include <X11/Xlib.h>

using namespace std::tr1::placeholders;

DECLARE_APP(tconsoleApp)

//(*IdInit(frmConsole)
const long frmConsole::ID_TEXTCTRL1 = wxNewId();
const long frmConsole::ID_BUTTON3 = wxNewId();
const long frmConsole::ID_BUTTON2 = wxNewId();
const long frmConsole::ID_HTMLWINDOW1 = wxNewId();
const long frmConsole::ID_PANEL1 = wxNewId();
const long frmConsole::ID_BUTTON1 = wxNewId();
const long frmConsole::ID_STATICTEXT1 = wxNewId();
const long frmConsole::ID_TEXTCTRL3 = wxNewId();
const long frmConsole::ID_STATICTEXT2 = wxNewId();
const long frmConsole::ID_TEXTCTRL4 = wxNewId();
const long frmConsole::ID_STATICTEXT3 = wxNewId();
const long frmConsole::ID_TEXTCTRL5 = wxNewId();
const long frmConsole::ID_STATICTEXT4 = wxNewId();
const long frmConsole::ID_TEXTCTRL6 = wxNewId();
const long frmConsole::ID_STATICTEXT5 = wxNewId();
const long frmConsole::ID_TEXTCTRL7 = wxNewId();
const long frmConsole::ID_STATICTEXT6 = wxNewId();
const long frmConsole::ID_TEXTCTRL8 = wxNewId();
const long frmConsole::ID_STATICTEXT7 = wxNewId();
const long frmConsole::ID_CHOICE1 = wxNewId();
const long frmConsole::ID_STATICTEXT8 = wxNewId();
const long frmConsole::ID_CHOICE2 = wxNewId();
const long frmConsole::ID_PANEL3 = wxNewId();
const long frmConsole::ID_GRID1 = wxNewId();
const long frmConsole::ID_PANEL4 = wxNewId();
const long frmConsole::ID_GRID2 = wxNewId();
const long frmConsole::ID_PANEL5 = wxNewId();
const long frmConsole::ID_GRID3 = wxNewId();
const long frmConsole::ID_PANEL6 = wxNewId();
const long frmConsole::ID_STATICTEXT9 = wxNewId();
const long frmConsole::ID_LBSCRIPT0 = wxNewId();
const long frmConsole::ID_STATICTEXT10 = wxNewId();
const long frmConsole::ID_LBSCRIPT1 = wxNewId();
const long frmConsole::ID_STATICTEXT11 = wxNewId();
const long frmConsole::ID_LBSCRIPT2 = wxNewId();
const long frmConsole::ID_STATICTEXT12 = wxNewId();
const long frmConsole::ID_LBSCRIPT3 = wxNewId();
const long frmConsole::ID_PANEL7 = wxNewId();
const long frmConsole::ID_STATICTEXT13 = wxNewId();
const long frmConsole::ID_CHOICE3 = wxNewId();
const long frmConsole::ID_STATICTEXT14 = wxNewId();
const long frmConsole::ID_CHOICE4 = wxNewId();
const long frmConsole::ID_PANEL8 = wxNewId();
const long frmConsole::ID_STATICTEXT15 = wxNewId();
const long frmConsole::ID_TEXTCTRL9 = wxNewId();
const long frmConsole::ID_STATICTEXT16 = wxNewId();
const long frmConsole::ID_TEXTCTRL10 = wxNewId();
const long frmConsole::ID_STATICTEXT17 = wxNewId();
const long frmConsole::ID_TEXTCTRL11 = wxNewId();
const long frmConsole::ID_STATICTEXT18 = wxNewId();
const long frmConsole::ID_TEXTCTRL12 = wxNewId();
const long frmConsole::ID_STATICTEXT19 = wxNewId();
const long frmConsole::ID_CHOICE5 = wxNewId();
const long frmConsole::ID_STATICTEXT20 = wxNewId();
const long frmConsole::ID_TEXTCTRL14 = wxNewId();
const long frmConsole::ID_STATICTEXT23 = wxNewId();
const long frmConsole::ID_TEXTCTRL15 = wxNewId();
const long frmConsole::ID_STATICTEXT21 = wxNewId();
const long frmConsole::ID_TEXTCTRL13 = wxNewId();
const long frmConsole::ID_STATICTEXT22 = wxNewId();
const long frmConsole::ID_CHECKBOX1 = wxNewId();
const long frmConsole::ID_PANEL13 = wxNewId();
const long frmConsole::ID_STATICTEXT24 = wxNewId();
const long frmConsole::ID_CHOICE6 = wxNewId();
const long frmConsole::ID_STATICTEXT25 = wxNewId();
const long frmConsole::ID_TEXTCTRL17 = wxNewId();
const long frmConsole::ID_STATICTEXT28 = wxNewId();
const long frmConsole::ID_TEXTCTRL18 = wxNewId();
const long frmConsole::ID_STATICTEXT26 = wxNewId();
const long frmConsole::ID_TEXTCTRL16 = wxNewId();
const long frmConsole::ID_STATICTEXT27 = wxNewId();
const long frmConsole::ID_CHECKBOX2 = wxNewId();
const long frmConsole::ID_PANEL14 = wxNewId();
const long frmConsole::ID_STATICTEXT29 = wxNewId();
const long frmConsole::ID_CHOICE7 = wxNewId();
const long frmConsole::ID_STATICTEXT30 = wxNewId();
const long frmConsole::ID_TEXTCTRL20 = wxNewId();
const long frmConsole::ID_STATICTEXT33 = wxNewId();
const long frmConsole::ID_TEXTCTRL21 = wxNewId();
const long frmConsole::ID_STATICTEXT31 = wxNewId();
const long frmConsole::ID_TEXTCTRL19 = wxNewId();
const long frmConsole::ID_STATICTEXT32 = wxNewId();
const long frmConsole::ID_CHECKBOX3 = wxNewId();
const long frmConsole::ID_PANEL15 = wxNewId();
const long frmConsole::ID_STATICTEXT34 = wxNewId();
const long frmConsole::ID_CHOICE8 = wxNewId();
const long frmConsole::ID_STATICTEXT35 = wxNewId();
const long frmConsole::ID_TEXTCTRL23 = wxNewId();
const long frmConsole::ID_STATICTEXT38 = wxNewId();
const long frmConsole::ID_TEXTCTRL24 = wxNewId();
const long frmConsole::ID_STATICTEXT36 = wxNewId();
const long frmConsole::ID_TEXTCTRL22 = wxNewId();
const long frmConsole::ID_STATICTEXT37 = wxNewId();
const long frmConsole::ID_CHECKBOX4 = wxNewId();
const long frmConsole::ID_PANEL16 = wxNewId();
const long frmConsole::ID_NOTEBOOK4 = wxNewId();
const long frmConsole::ID_PANEL11 = wxNewId();
const long frmConsole::ID_STATICTEXT39 = wxNewId();
const long frmConsole::ID_TEXTCTRL25 = wxNewId();
const long frmConsole::ID_STATICTEXT40 = wxNewId();
const long frmConsole::ID_TEXTCTRL26 = wxNewId();
const long frmConsole::ID_STATICTEXT41 = wxNewId();
const long frmConsole::ID_TEXTCTRL27 = wxNewId();
const long frmConsole::ID_STATICTEXT42 = wxNewId();
const long frmConsole::ID_TEXTCTRL28 = wxNewId();
const long frmConsole::ID_STATICTEXT43 = wxNewId();
const long frmConsole::ID_CHOICE9 = wxNewId();
const long frmConsole::ID_STATICTEXT44 = wxNewId();
const long frmConsole::ID_TEXTCTRL30 = wxNewId();
const long frmConsole::ID_STATICTEXT47 = wxNewId();
const long frmConsole::ID_TEXTCTRL31 = wxNewId();
const long frmConsole::ID_STATICTEXT45 = wxNewId();
const long frmConsole::ID_TEXTCTRL29 = wxNewId();
const long frmConsole::ID_STATICTEXT46 = wxNewId();
const long frmConsole::ID_CHECKBOX5 = wxNewId();
const long frmConsole::ID_PANEL17 = wxNewId();
const long frmConsole::ID_STATICTEXT48 = wxNewId();
const long frmConsole::ID_CHOICE10 = wxNewId();
const long frmConsole::ID_STATICTEXT49 = wxNewId();
const long frmConsole::ID_TEXTCTRL33 = wxNewId();
const long frmConsole::ID_STATICTEXT52 = wxNewId();
const long frmConsole::ID_TEXTCTRL34 = wxNewId();
const long frmConsole::ID_STATICTEXT50 = wxNewId();
const long frmConsole::ID_TEXTCTRL32 = wxNewId();
const long frmConsole::ID_STATICTEXT51 = wxNewId();
const long frmConsole::ID_CHECKBOX6 = wxNewId();
const long frmConsole::ID_PANEL18 = wxNewId();
const long frmConsole::ID_STATICTEXT53 = wxNewId();
const long frmConsole::ID_CHOICE11 = wxNewId();
const long frmConsole::ID_STATICTEXT54 = wxNewId();
const long frmConsole::ID_TEXTCTRL36 = wxNewId();
const long frmConsole::ID_STATICTEXT57 = wxNewId();
const long frmConsole::ID_TEXTCTRL37 = wxNewId();
const long frmConsole::ID_STATICTEXT55 = wxNewId();
const long frmConsole::ID_TEXTCTRL35 = wxNewId();
const long frmConsole::ID_STATICTEXT56 = wxNewId();
const long frmConsole::ID_CHECKBOX7 = wxNewId();
const long frmConsole::ID_PANEL19 = wxNewId();
const long frmConsole::ID_STATICTEXT58 = wxNewId();
const long frmConsole::ID_CHOICE12 = wxNewId();
const long frmConsole::ID_STATICTEXT59 = wxNewId();
const long frmConsole::ID_TEXTCTRL39 = wxNewId();
const long frmConsole::ID_STATICTEXT62 = wxNewId();
const long frmConsole::ID_TEXTCTRL40 = wxNewId();
const long frmConsole::ID_STATICTEXT60 = wxNewId();
const long frmConsole::ID_TEXTCTRL38 = wxNewId();
const long frmConsole::ID_STATICTEXT61 = wxNewId();
const long frmConsole::ID_CHECKBOX8 = wxNewId();
const long frmConsole::ID_PANEL20 = wxNewId();
const long frmConsole::ID_NOTEBOOK5 = wxNewId();
const long frmConsole::ID_PANEL12 = wxNewId();
const long frmConsole::ID_NOTEBOOK3 = wxNewId();
const long frmConsole::ID_PANEL9 = wxNewId();
const long frmConsole::ID_CHOICE13 = wxNewId();
const long frmConsole::ID_STATICTEXT63 = wxNewId();
const long frmConsole::ID_CHOICE14 = wxNewId();
const long frmConsole::ID_STATICTEXT64 = wxNewId();
const long frmConsole::ID_TEXTCTRL41 = wxNewId();
const long frmConsole::ID_STATICTEXT65 = wxNewId();
const long frmConsole::ID_TEXTCTRL42 = wxNewId();
const long frmConsole::ID_STATICTEXT66 = wxNewId();
const long frmConsole::ID_TEXTCTRL43 = wxNewId();
const long frmConsole::ID_STATICTEXT67 = wxNewId();
const long frmConsole::ID_CHOICE15 = wxNewId();
const long frmConsole::ID_CHECKBOX18 = wxNewId();
const long frmConsole::ID_TEXTCTRL47 = wxNewId();
const long frmConsole::ID_STATICTEXT77 = wxNewId();
const long frmConsole::ID_STATICTEXT68 = wxNewId();
const long frmConsole::ID_STATICTEXT69 = wxNewId();
const long frmConsole::ID_CHOICE16 = wxNewId();
const long frmConsole::ID_STATICTEXT70 = wxNewId();
const long frmConsole::ID_STATICTEXT71 = wxNewId();
const long frmConsole::ID_TEXTCTRL44 = wxNewId();
const long frmConsole::ID_STATICTEXT72 = wxNewId();
const long frmConsole::ID_TEXTCTRL45 = wxNewId();
const long frmConsole::ID_STATICTEXT73 = wxNewId();
const long frmConsole::ID_TEXTCTRL46 = wxNewId();
const long frmConsole::ID_STATICTEXT74 = wxNewId();
const long frmConsole::ID_STATICTEXT75 = wxNewId();
const long frmConsole::ID_CHECKBOX9 = wxNewId();
const long frmConsole::ID_STATICTEXT76 = wxNewId();
const long frmConsole::ID_CHECKBOX10 = wxNewId();
const long frmConsole::ID_CHECKBOX11 = wxNewId();
const long frmConsole::ID_CHECKBOX12 = wxNewId();
const long frmConsole::ID_CHECKBOX13 = wxNewId();
const long frmConsole::ID_CHECKBOX14 = wxNewId();
const long frmConsole::ID_CHECKBOX15 = wxNewId();
const long frmConsole::ID_CHECKBOX16 = wxNewId();
const long frmConsole::ID_CHECKBOX17 = wxNewId();
const long frmConsole::ID_PANEL21 = wxNewId();
const long frmConsole::ID_CHOICE17 = wxNewId();
const long frmConsole::ID_STATICTEXT78 = wxNewId();
const long frmConsole::ID_CHOICE18 = wxNewId();
const long frmConsole::ID_STATICTEXT79 = wxNewId();
const long frmConsole::ID_TEXTCTRL48 = wxNewId();
const long frmConsole::ID_STATICTEXT80 = wxNewId();
const long frmConsole::ID_TEXTCTRL49 = wxNewId();
const long frmConsole::ID_STATICTEXT81 = wxNewId();
const long frmConsole::ID_TEXTCTRL50 = wxNewId();
const long frmConsole::ID_STATICTEXT82 = wxNewId();
const long frmConsole::ID_CHOICE19 = wxNewId();
const long frmConsole::ID_CHECKBOX19 = wxNewId();
const long frmConsole::ID_TEXTCTRL51 = wxNewId();
const long frmConsole::ID_STATICTEXT83 = wxNewId();
const long frmConsole::ID_STATICTEXT84 = wxNewId();
const long frmConsole::ID_STATICTEXT85 = wxNewId();
const long frmConsole::ID_CHOICE20 = wxNewId();
const long frmConsole::ID_STATICTEXT86 = wxNewId();
const long frmConsole::ID_STATICTEXT87 = wxNewId();
const long frmConsole::ID_TEXTCTRL52 = wxNewId();
const long frmConsole::ID_STATICTEXT88 = wxNewId();
const long frmConsole::ID_TEXTCTRL53 = wxNewId();
const long frmConsole::ID_STATICTEXT89 = wxNewId();
const long frmConsole::ID_TEXTCTRL54 = wxNewId();
const long frmConsole::ID_STATICTEXT90 = wxNewId();
const long frmConsole::ID_STATICTEXT91 = wxNewId();
const long frmConsole::ID_CHECKBOX20 = wxNewId();
const long frmConsole::ID_STATICTEXT92 = wxNewId();
const long frmConsole::ID_CHECKBOX21 = wxNewId();
const long frmConsole::ID_CHECKBOX22 = wxNewId();
const long frmConsole::ID_CHECKBOX23 = wxNewId();
const long frmConsole::ID_CHECKBOX24 = wxNewId();
const long frmConsole::ID_CHECKBOX25 = wxNewId();
const long frmConsole::ID_CHECKBOX26 = wxNewId();
const long frmConsole::ID_CHECKBOX27 = wxNewId();
const long frmConsole::ID_CHECKBOX28 = wxNewId();
const long frmConsole::ID_PANEL22 = wxNewId();
const long frmConsole::ID_CHOICE21 = wxNewId();
const long frmConsole::ID_STATICTEXT93 = wxNewId();
const long frmConsole::ID_CHOICE22 = wxNewId();
const long frmConsole::ID_STATICTEXT94 = wxNewId();
const long frmConsole::ID_TEXTCTRL55 = wxNewId();
const long frmConsole::ID_STATICTEXT95 = wxNewId();
const long frmConsole::ID_TEXTCTRL56 = wxNewId();
const long frmConsole::ID_STATICTEXT96 = wxNewId();
const long frmConsole::ID_TEXTCTRL57 = wxNewId();
const long frmConsole::ID_STATICTEXT97 = wxNewId();
const long frmConsole::ID_CHOICE23 = wxNewId();
const long frmConsole::ID_CHECKBOX29 = wxNewId();
const long frmConsole::ID_TEXTCTRL58 = wxNewId();
const long frmConsole::ID_STATICTEXT98 = wxNewId();
const long frmConsole::ID_STATICTEXT99 = wxNewId();
const long frmConsole::ID_STATICTEXT100 = wxNewId();
const long frmConsole::ID_CHOICE24 = wxNewId();
const long frmConsole::ID_STATICTEXT101 = wxNewId();
const long frmConsole::ID_STATICTEXT102 = wxNewId();
const long frmConsole::ID_TEXTCTRL59 = wxNewId();
const long frmConsole::ID_STATICTEXT103 = wxNewId();
const long frmConsole::ID_TEXTCTRL60 = wxNewId();
const long frmConsole::ID_STATICTEXT104 = wxNewId();
const long frmConsole::ID_TEXTCTRL61 = wxNewId();
const long frmConsole::ID_STATICTEXT105 = wxNewId();
const long frmConsole::ID_STATICTEXT106 = wxNewId();
const long frmConsole::ID_CHECKBOX30 = wxNewId();
const long frmConsole::ID_STATICTEXT107 = wxNewId();
const long frmConsole::ID_CHECKBOX31 = wxNewId();
const long frmConsole::ID_CHECKBOX32 = wxNewId();
const long frmConsole::ID_CHECKBOX33 = wxNewId();
const long frmConsole::ID_CHECKBOX34 = wxNewId();
const long frmConsole::ID_CHECKBOX35 = wxNewId();
const long frmConsole::ID_CHECKBOX36 = wxNewId();
const long frmConsole::ID_CHECKBOX37 = wxNewId();
const long frmConsole::ID_CHECKBOX38 = wxNewId();
const long frmConsole::ID_PANEL23 = wxNewId();
const long frmConsole::ID_CHOICE25 = wxNewId();
const long frmConsole::ID_STATICTEXT108 = wxNewId();
const long frmConsole::ID_CHOICE26 = wxNewId();
const long frmConsole::ID_STATICTEXT109 = wxNewId();
const long frmConsole::ID_TEXTCTRL62 = wxNewId();
const long frmConsole::ID_STATICTEXT110 = wxNewId();
const long frmConsole::ID_TEXTCTRL63 = wxNewId();
const long frmConsole::ID_STATICTEXT111 = wxNewId();
const long frmConsole::ID_TEXTCTRL64 = wxNewId();
const long frmConsole::ID_STATICTEXT112 = wxNewId();
const long frmConsole::ID_CHOICE27 = wxNewId();
const long frmConsole::ID_CHECKBOX39 = wxNewId();
const long frmConsole::ID_TEXTCTRL65 = wxNewId();
const long frmConsole::ID_STATICTEXT113 = wxNewId();
const long frmConsole::ID_STATICTEXT114 = wxNewId();
const long frmConsole::ID_STATICTEXT115 = wxNewId();
const long frmConsole::ID_CHOICE28 = wxNewId();
const long frmConsole::ID_STATICTEXT116 = wxNewId();
const long frmConsole::ID_STATICTEXT117 = wxNewId();
const long frmConsole::ID_TEXTCTRL66 = wxNewId();
const long frmConsole::ID_STATICTEXT118 = wxNewId();
const long frmConsole::ID_TEXTCTRL67 = wxNewId();
const long frmConsole::ID_STATICTEXT119 = wxNewId();
const long frmConsole::ID_TEXTCTRL68 = wxNewId();
const long frmConsole::ID_STATICTEXT120 = wxNewId();
const long frmConsole::ID_STATICTEXT121 = wxNewId();
const long frmConsole::ID_CHECKBOX40 = wxNewId();
const long frmConsole::ID_STATICTEXT122 = wxNewId();
const long frmConsole::ID_CHECKBOX41 = wxNewId();
const long frmConsole::ID_CHECKBOX42 = wxNewId();
const long frmConsole::ID_CHECKBOX43 = wxNewId();
const long frmConsole::ID_CHECKBOX44 = wxNewId();
const long frmConsole::ID_CHECKBOX45 = wxNewId();
const long frmConsole::ID_CHECKBOX46 = wxNewId();
const long frmConsole::ID_CHECKBOX47 = wxNewId();
const long frmConsole::ID_CHECKBOX48 = wxNewId();
const long frmConsole::ID_PANEL24 = wxNewId();
const long frmConsole::ID_CHOICE29 = wxNewId();
const long frmConsole::ID_STATICTEXT123 = wxNewId();
const long frmConsole::ID_CHOICE30 = wxNewId();
const long frmConsole::ID_STATICTEXT124 = wxNewId();
const long frmConsole::ID_TEXTCTRL69 = wxNewId();
const long frmConsole::ID_STATICTEXT125 = wxNewId();
const long frmConsole::ID_TEXTCTRL70 = wxNewId();
const long frmConsole::ID_STATICTEXT126 = wxNewId();
const long frmConsole::ID_TEXTCTRL71 = wxNewId();
const long frmConsole::ID_STATICTEXT127 = wxNewId();
const long frmConsole::ID_CHOICE31 = wxNewId();
const long frmConsole::ID_CHECKBOX49 = wxNewId();
const long frmConsole::ID_TEXTCTRL72 = wxNewId();
const long frmConsole::ID_STATICTEXT128 = wxNewId();
const long frmConsole::ID_STATICTEXT129 = wxNewId();
const long frmConsole::ID_STATICTEXT130 = wxNewId();
const long frmConsole::ID_CHOICE32 = wxNewId();
const long frmConsole::ID_STATICTEXT131 = wxNewId();
const long frmConsole::ID_STATICTEXT132 = wxNewId();
const long frmConsole::ID_TEXTCTRL73 = wxNewId();
const long frmConsole::ID_STATICTEXT133 = wxNewId();
const long frmConsole::ID_TEXTCTRL74 = wxNewId();
const long frmConsole::ID_STATICTEXT134 = wxNewId();
const long frmConsole::ID_TEXTCTRL75 = wxNewId();
const long frmConsole::ID_STATICTEXT135 = wxNewId();
const long frmConsole::ID_STATICTEXT136 = wxNewId();
const long frmConsole::ID_CHECKBOX50 = wxNewId();
const long frmConsole::ID_STATICTEXT137 = wxNewId();
const long frmConsole::ID_CHECKBOX51 = wxNewId();
const long frmConsole::ID_CHECKBOX52 = wxNewId();
const long frmConsole::ID_CHECKBOX53 = wxNewId();
const long frmConsole::ID_CHECKBOX54 = wxNewId();
const long frmConsole::ID_CHECKBOX55 = wxNewId();
const long frmConsole::ID_CHECKBOX56 = wxNewId();
const long frmConsole::ID_CHECKBOX57 = wxNewId();
const long frmConsole::ID_CHECKBOX58 = wxNewId();
const long frmConsole::ID_PANEL25 = wxNewId();
const long frmConsole::ID_CHOICE33 = wxNewId();
const long frmConsole::ID_STATICTEXT138 = wxNewId();
const long frmConsole::ID_CHOICE34 = wxNewId();
const long frmConsole::ID_STATICTEXT139 = wxNewId();
const long frmConsole::ID_TEXTCTRL76 = wxNewId();
const long frmConsole::ID_STATICTEXT140 = wxNewId();
const long frmConsole::ID_TEXTCTRL77 = wxNewId();
const long frmConsole::ID_STATICTEXT141 = wxNewId();
const long frmConsole::ID_TEXTCTRL78 = wxNewId();
const long frmConsole::ID_STATICTEXT142 = wxNewId();
const long frmConsole::ID_CHOICE35 = wxNewId();
const long frmConsole::ID_CHECKBOX59 = wxNewId();
const long frmConsole::ID_TEXTCTRL79 = wxNewId();
const long frmConsole::ID_STATICTEXT143 = wxNewId();
const long frmConsole::ID_STATICTEXT144 = wxNewId();
const long frmConsole::ID_STATICTEXT145 = wxNewId();
const long frmConsole::ID_CHOICE36 = wxNewId();
const long frmConsole::ID_STATICTEXT146 = wxNewId();
const long frmConsole::ID_STATICTEXT147 = wxNewId();
const long frmConsole::ID_TEXTCTRL80 = wxNewId();
const long frmConsole::ID_STATICTEXT148 = wxNewId();
const long frmConsole::ID_TEXTCTRL81 = wxNewId();
const long frmConsole::ID_STATICTEXT149 = wxNewId();
const long frmConsole::ID_TEXTCTRL82 = wxNewId();
const long frmConsole::ID_STATICTEXT150 = wxNewId();
const long frmConsole::ID_STATICTEXT151 = wxNewId();
const long frmConsole::ID_CHECKBOX60 = wxNewId();
const long frmConsole::ID_STATICTEXT152 = wxNewId();
const long frmConsole::ID_CHECKBOX61 = wxNewId();
const long frmConsole::ID_CHECKBOX62 = wxNewId();
const long frmConsole::ID_CHECKBOX63 = wxNewId();
const long frmConsole::ID_CHECKBOX64 = wxNewId();
const long frmConsole::ID_CHECKBOX65 = wxNewId();
const long frmConsole::ID_CHECKBOX66 = wxNewId();
const long frmConsole::ID_CHECKBOX67 = wxNewId();
const long frmConsole::ID_CHECKBOX68 = wxNewId();
const long frmConsole::ID_PANEL26 = wxNewId();
const long frmConsole::ID_CHOICE37 = wxNewId();
const long frmConsole::ID_STATICTEXT153 = wxNewId();
const long frmConsole::ID_CHOICE38 = wxNewId();
const long frmConsole::ID_STATICTEXT154 = wxNewId();
const long frmConsole::ID_TEXTCTRL83 = wxNewId();
const long frmConsole::ID_STATICTEXT155 = wxNewId();
const long frmConsole::ID_TEXTCTRL84 = wxNewId();
const long frmConsole::ID_STATICTEXT156 = wxNewId();
const long frmConsole::ID_TEXTCTRL85 = wxNewId();
const long frmConsole::ID_STATICTEXT157 = wxNewId();
const long frmConsole::ID_CHOICE39 = wxNewId();
const long frmConsole::ID_CHECKBOX69 = wxNewId();
const long frmConsole::ID_TEXTCTRL86 = wxNewId();
const long frmConsole::ID_STATICTEXT158 = wxNewId();
const long frmConsole::ID_STATICTEXT159 = wxNewId();
const long frmConsole::ID_STATICTEXT160 = wxNewId();
const long frmConsole::ID_CHOICE40 = wxNewId();
const long frmConsole::ID_STATICTEXT161 = wxNewId();
const long frmConsole::ID_STATICTEXT162 = wxNewId();
const long frmConsole::ID_TEXTCTRL87 = wxNewId();
const long frmConsole::ID_STATICTEXT163 = wxNewId();
const long frmConsole::ID_TEXTCTRL88 = wxNewId();
const long frmConsole::ID_STATICTEXT164 = wxNewId();
const long frmConsole::ID_TEXTCTRL89 = wxNewId();
const long frmConsole::ID_STATICTEXT165 = wxNewId();
const long frmConsole::ID_STATICTEXT166 = wxNewId();
const long frmConsole::ID_CHECKBOX70 = wxNewId();
const long frmConsole::ID_STATICTEXT167 = wxNewId();
const long frmConsole::ID_CHECKBOX71 = wxNewId();
const long frmConsole::ID_CHECKBOX72 = wxNewId();
const long frmConsole::ID_CHECKBOX73 = wxNewId();
const long frmConsole::ID_CHECKBOX74 = wxNewId();
const long frmConsole::ID_CHECKBOX75 = wxNewId();
const long frmConsole::ID_CHECKBOX76 = wxNewId();
const long frmConsole::ID_CHECKBOX77 = wxNewId();
const long frmConsole::ID_CHECKBOX78 = wxNewId();
const long frmConsole::ID_PANEL27 = wxNewId();
const long frmConsole::ID_CHOICE41 = wxNewId();
const long frmConsole::ID_STATICTEXT168 = wxNewId();
const long frmConsole::ID_CHOICE42 = wxNewId();
const long frmConsole::ID_STATICTEXT169 = wxNewId();
const long frmConsole::ID_TEXTCTRL90 = wxNewId();
const long frmConsole::ID_STATICTEXT170 = wxNewId();
const long frmConsole::ID_TEXTCTRL91 = wxNewId();
const long frmConsole::ID_STATICTEXT171 = wxNewId();
const long frmConsole::ID_TEXTCTRL92 = wxNewId();
const long frmConsole::ID_STATICTEXT172 = wxNewId();
const long frmConsole::ID_CHOICE43 = wxNewId();
const long frmConsole::ID_CHECKBOX79 = wxNewId();
const long frmConsole::ID_TEXTCTRL93 = wxNewId();
const long frmConsole::ID_STATICTEXT173 = wxNewId();
const long frmConsole::ID_STATICTEXT174 = wxNewId();
const long frmConsole::ID_STATICTEXT175 = wxNewId();
const long frmConsole::ID_CHOICE44 = wxNewId();
const long frmConsole::ID_STATICTEXT176 = wxNewId();
const long frmConsole::ID_STATICTEXT177 = wxNewId();
const long frmConsole::ID_TEXTCTRL94 = wxNewId();
const long frmConsole::ID_STATICTEXT178 = wxNewId();
const long frmConsole::ID_TEXTCTRL95 = wxNewId();
const long frmConsole::ID_STATICTEXT179 = wxNewId();
const long frmConsole::ID_TEXTCTRL96 = wxNewId();
const long frmConsole::ID_STATICTEXT180 = wxNewId();
const long frmConsole::ID_STATICTEXT181 = wxNewId();
const long frmConsole::ID_CHECKBOX80 = wxNewId();
const long frmConsole::ID_STATICTEXT182 = wxNewId();
const long frmConsole::ID_CHECKBOX81 = wxNewId();
const long frmConsole::ID_CHECKBOX82 = wxNewId();
const long frmConsole::ID_CHECKBOX83 = wxNewId();
const long frmConsole::ID_CHECKBOX84 = wxNewId();
const long frmConsole::ID_CHECKBOX85 = wxNewId();
const long frmConsole::ID_CHECKBOX86 = wxNewId();
const long frmConsole::ID_CHECKBOX87 = wxNewId();
const long frmConsole::ID_CHECKBOX88 = wxNewId();
const long frmConsole::ID_PANEL28 = wxNewId();
const long frmConsole::ID_NOTEBOOK6 = wxNewId();
const long frmConsole::ID_PANEL10 = wxNewId();
const long frmConsole::ID_NOTEBOOK2 = wxNewId();
const long frmConsole::ID_PANEL2 = wxNewId();
const long frmConsole::ID_NOTEBOOK1 = wxNewId();
const long frmConsole::ID_TEXTCTRL2 = wxNewId();
//*)

const long frmConsole::ID_OUT = wxNewId();

BEGIN_EVENT_TABLE(frmConsole,wxMDIChildFrame)
	//(*EventTable(frmConsole)
	//*)
	EVT_THREAD(ID_OUT, frmConsole::OnAction)
	//EVT_THREAD(ID_OUT_103, frmConsole::OnOut103)
END_EVENT_TABLE()

frmConsole::frmConsole(wxMDIParentFrame* parent,wxWindowID id)
: wxMDIChildFrame(parent, id, wxT("console"), wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL)
//, wxScrolled<wxWindow>(parent, id)
{
  this->parent=(frmMain *)parent;
  RemoteNode=0;
  lCmdHistory.push_back(wxT(""));
  lastCmd=lCmdHistory.begin();
  mBaud[9600]=0;
  mBaud[19200]=1;
  mBaud[38400]=2;
  mBaud[57500]=3;
  mBaud[115200]=4;

	//(*Initialize(frmConsole)
	wxBoxSizer* BoxSizer15;
	wxFlexGridSizer* FlexGridSizer30;
	wxFlexGridSizer* FlexGridSizer21;
	wxFlexGridSizer* FlexGridSizer28;
	wxFlexGridSizer* FlexGridSizer8;
	wxBoxSizer* BoxSizer33;
	wxGridSizer* GridSizer1;
	wxBoxSizer* BoxSizer32;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer25;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer15;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer16;
	wxBoxSizer* BoxSizer27;
	wxFlexGridSizer* FlexGridSizer17;
	wxBoxSizer* BoxSizer10;
	wxGridSizer* GridSizer3;
	wxFlexGridSizer* FlexGridSizer29;
	wxBoxSizer* BoxSizer25;
	wxFlexGridSizer* FlexGridSizer19;
	wxFlexGridSizer* FlexGridSizer11;
	wxFlexGridSizer* FlexGridSizer41;
	wxBoxSizer* BoxSizer29;
	wxBoxSizer* BoxSizer24;
	wxBoxSizer* BoxSizer7;
	wxFlexGridSizer* FlexGridSizer40;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer22;
	wxFlexGridSizer* FlexGridSizer7;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer28;
	wxFlexGridSizer* FlexGridSizer4;
	wxBoxSizer* BoxSizer31;
	wxFlexGridSizer* FlexGridSizer26;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer14;
	wxFlexGridSizer* FlexGridSizer33;
	wxBoxSizer* BoxSizer17;
	wxFlexGridSizer* FlexGridSizer6;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer18;
	wxFlexGridSizer* FlexGridSizer38;
	wxBoxSizer* BoxSizer21;
	wxBoxSizer* BoxSizer34;
	wxFlexGridSizer* FlexGridSizer42;
	wxFlexGridSizer* FlexGridSizer37;
	wxFlexGridSizer* FlexGridSizer27;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer22;
	wxFlexGridSizer* FlexGridSizer31;
	wxBoxSizer* BoxSizer19;
	wxFlexGridSizer* FlexGridSizer43;
	wxBoxSizer* BoxSizer4;
	wxFlexGridSizer* FlexGridSizer39;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer35;
	wxBoxSizer* BoxSizer30;
	wxBoxSizer* BoxSizer36;
	wxFlexGridSizer* FlexGridSizer34;
	wxFlexGridSizer* FlexGridSizer16;
	wxBoxSizer* BoxSizer23;
	wxFlexGridSizer* FlexGridSizer23;
	wxBoxSizer* BoxSizer20;
	wxFlexGridSizer* FlexGridSizer10;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer37;
	wxFlexGridSizer* FlexGridSizer13;
	wxFlexGridSizer* FlexGridSizer18;
	wxFlexGridSizer* FlexGridSizer36;
	wxFlexGridSizer* FlexGridSizer12;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer14;
	wxFlexGridSizer* FlexGridSizer44;
	wxFlexGridSizer* FlexGridSizer35;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer24;
	wxBoxSizer* BoxSizer26;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxFlexGridSizer* FlexGridSizer32;
	wxFlexGridSizer* FlexGridSizer20;

	//Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	SetClientSize(wxSize(643,436));
	SetFocus();
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	tcNode = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	tcNode->SetFocus();
	BoxSizer1->Add(tcNode, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(1025,743), wxTAB_TRAVERSAL|wxVSCROLL|wxHSCROLL, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	bDownload = new wxButton(Panel1, ID_BUTTON3, _("Download"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer4->Add(bDownload, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	bUpload = new wxButton(Panel1, ID_BUTTON2, _("Upload"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(bUpload, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	htmlOut = new wxHtmlWindow(Panel1, ID_HTMLWINDOW1, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO, _T("ID_HTMLWINDOW1"));
	BoxSizer2->Add(htmlOut, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	bRefresh = new wxButton(Panel2, ID_BUTTON1, _("Refresh"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(bRefresh, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	nbConfig = new wxNotebook(Panel2, ID_NOTEBOOK2, wxDefaultPosition, wxSize(886,565), wxVSCROLL|wxHSCROLL, _T("ID_NOTEBOOK2"));
	pGeneral = new wxPanel(nbConfig, ID_PANEL3, wxDefaultPosition, wxSize(679,301), wxSTATIC_BORDER|wxTAB_TRAVERSAL|wxVSCROLL|wxHSCROLL, _T("ID_PANEL3"));
	pGeneral->SetMinSize(wxSize(200,300));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(pGeneral, ID_STATICTEXT1, _("IP Connect Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcIpConnTimeout = new wxTextCtrl(pGeneral, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxSize(250,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(tcIpConnTimeout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(pGeneral, ID_STATICTEXT2, _("GPRS Connect Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcGprsConnTimeout = new wxTextCtrl(pGeneral, ID_TEXTCTRL4, _("0"), wxDefaultPosition, wxSize(250,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(tcGprsConnTimeout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(pGeneral, ID_STATICTEXT3, _("Max IP Power-up Delay, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcMaxIpPwrDelay = new wxTextCtrl(pGeneral, ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxSize(250,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	FlexGridSizer1->Add(tcMaxIpPwrDelay, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(pGeneral, ID_STATICTEXT4, _("CSQ Minimum Value"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcCSQMinVal = new wxTextCtrl(pGeneral, ID_TEXTCTRL6, _("0"), wxDefaultPosition, wxSize(250,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	FlexGridSizer1->Add(tcCSQMinVal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(pGeneral, ID_STATICTEXT5, _("IP Packet Max Length"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcIpPacketMaxLen = new wxTextCtrl(pGeneral, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxSize(250,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	FlexGridSizer1->Add(tcIpPacketMaxLen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(pGeneral, ID_STATICTEXT6, _("Trace Answer"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcTraceAnswer = new wxTextCtrl(pGeneral, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(250,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	FlexGridSizer1->Add(tcTraceAnswer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(pGeneral, ID_STATICTEXT7, _("Debug"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chDebug = new wxChoice(pGeneral, ID_CHOICE1, wxDefaultPosition, wxSize(250,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	chDebug->SetSelection( chDebug->Append(_("Disabled")) );
	chDebug->Append(_("Enabled"));
	FlexGridSizer1->Add(chDebug, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(pGeneral, ID_STATICTEXT8, _("Channel Priority"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chChanPrior = new wxChoice(pGeneral, ID_CHOICE2, wxDefaultPosition, wxSize(250,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	chChanPrior->Append(_("Disabled"));
	chChanPrior->SetSelection( chChanPrior->Append(_("IP")) );
	FlexGridSizer1->Add(chChanPrior, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pGeneral->SetSizer(FlexGridSizer1);
	FlexGridSizer1->SetSizeHints(pGeneral);
	pGprs = new wxPanel(nbConfig, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	gGprs = new wxGrid(pGprs, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
	gGprs->CreateGrid(7,5);
	gGprs->EnableEditing(false);
	gGprs->EnableGridLines(true);
	gGprs->SetDefaultColSize(130, true);
	gGprs->SetColLabelValue(0, _("Operator ID"));
	gGprs->SetColLabelValue(1, _("User Name"));
	gGprs->SetColLabelValue(2, _("Password"));
	gGprs->SetColLabelValue(3, _("APN"));
	gGprs->SetColLabelValue(4, _("Auto Disconnect, sec"));
	gGprs->SetDefaultCellFont( gGprs->GetFont() );
	gGprs->SetDefaultCellTextColour( gGprs->GetForegroundColour() );
	BoxSizer5->Add(gGprs, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pGprs->SetSizer(BoxSizer5);
	BoxSizer5->Fit(pGprs);
	BoxSizer5->SetSizeHints(pGprs);
	pServer = new wxPanel(nbConfig, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	gServer = new wxGrid(pServer, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
	gServer->CreateGrid(7,5);
	gServer->EnableEditing(false);
	gServer->EnableGridLines(true);
	gServer->SetDefaultColSize(130, true);
	gServer->SetColLabelValue(0, _("Server Node"));
	gServer->SetColLabelValue(1, _("Server IP"));
	gServer->SetColLabelValue(2, _("Server Port"));
	gServer->SetColLabelValue(3, _("KA Send, sec"));
	gServer->SetColLabelValue(4, _("KA Receive, sec"));
	gServer->SetDefaultCellFont( gServer->GetFont() );
	gServer->SetDefaultCellTextColour( gServer->GetForegroundColour() );
	BoxSizer6->Add(gServer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pServer->SetSizer(BoxSizer6);
	BoxSizer6->Fit(pServer);
	BoxSizer6->SetSizeHints(pServer);
	pVip = new wxPanel(nbConfig, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	gVip = new wxGrid(pVip, ID_GRID3, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID3"));
	gVip->CreateGrid(7,9);
	gVip->EnableEditing(true);
	gVip->EnableGridLines(true);
	gVip->SetDefaultColSize(100, true);
	gVip->SetColLabelValue(0, _("Server Node"));
	gVip->SetColLabelValue(1, _("Server Itf"));
	gVip->SetColLabelValue(2, _("Flags"));
	gVip->SetColLabelValue(3, _("KA Send, sec"));
	gVip->SetColLabelValue(4, _("KA Recv, sec"));
	gVip->SetColLabelValue(5, _("Idle Time, sec"));
	gVip->SetColLabelValue(6, _("Connect Timeout, sec"));
	gVip->SetColLabelValue(7, _("Connection Time, sec"));
	gVip->SetColLabelValue(8, _("Reserve Host"));
	gVip->SetDefaultCellFont( gVip->GetFont() );
	gVip->SetDefaultCellTextColour( gVip->GetForegroundColour() );
	BoxSizer7->Add(gVip, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVip->SetSizer(BoxSizer7);
	BoxSizer7->Fit(pVip);
	BoxSizer7->SetSizeHints(pVip);
	pScripts = new wxPanel(nbConfig, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
	GridSizer1 = new wxGridSizer(2, 2, 0, 0);
	BoxSizer8 = new wxBoxSizer(wxVERTICAL);
	StaticText9 = new wxStaticText(pScripts, ID_STATICTEXT9, _("Script 0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer8->Add(StaticText9, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	lbScript0 = new wxListBox(pScripts, ID_LBSCRIPT0, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LBSCRIPT0"));
	BoxSizer8->Add(lbScript0, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(BoxSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9 = new wxBoxSizer(wxVERTICAL);
	StaticText10 = new wxStaticText(pScripts, ID_STATICTEXT10, _("Script 1"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer9->Add(StaticText10, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	lbScript1 = new wxListBox(pScripts, ID_LBSCRIPT1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LBSCRIPT1"));
	BoxSizer9->Add(lbScript1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(BoxSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	StaticText11 = new wxStaticText(pScripts, ID_STATICTEXT11, _("Script 2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer10->Add(StaticText11, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	lbScript2 = new wxListBox(pScripts, ID_LBSCRIPT2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LBSCRIPT2"));
	BoxSizer10->Add(lbScript2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(BoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxVERTICAL);
	StaticText12 = new wxStaticText(pScripts, ID_STATICTEXT12, _("Script 3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer11->Add(StaticText12, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	lbScript3 = new wxListBox(pScripts, ID_LBSCRIPT3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LBSCRIPT3"));
	BoxSizer11->Add(lbScript3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(BoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pScripts->SetSizer(GridSizer1);
	GridSizer1->Fit(pScripts);
	GridSizer1->SetSizeHints(pScripts);
	pSerial = new wxPanel(nbConfig, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText13 = new wxStaticText(pSerial, ID_STATICTEXT13, _("Budrate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer2->Add(StaticText13, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chBaud = new wxChoice(pSerial, ID_CHOICE3, wxDefaultPosition, wxSize(195,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	chBaud->SetSelection( chBaud->Append(_("9600")) );
	chBaud->Append(_("19200"));
	chBaud->Append(_("38400"));
	chBaud->Append(_("57600"));
	chBaud->Append(_("115200"));
	FlexGridSizer2->Add(chBaud, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(pSerial, ID_STATICTEXT14, _("Flow Control"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer2->Add(StaticText14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chFlowCtrl = new wxChoice(pSerial, ID_CHOICE4, wxDefaultPosition, wxSize(195,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	chFlowCtrl->SetSelection( chFlowCtrl->Append(_("Off")) );
	chFlowCtrl->Append(_("Hardware"));
	FlexGridSizer2->Add(chFlowCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pSerial->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(pSerial);
	FlexGridSizer2->SetSizeHints(pSerial);
	pEthernet = new wxPanel(nbConfig, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxVSCROLL|wxALWAYS_SHOW_SB, _T("ID_PANEL9"));
	GridSizer2 = new wxGridSizer(0, 1, 0, 0);
	nbEthernet = new wxNotebook(pEthernet, ID_NOTEBOOK3, wxDefaultPosition, wxSize(868,702), 0, _T("ID_NOTEBOOK3"));
	pEthernet0 = new wxPanel(nbEthernet, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL11"));
	BoxSizer12 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText15 = new wxStaticText(pEthernet0, ID_STATICTEXT15, _("MAC Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	FlexGridSizer3->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth0Mac = new wxTextCtrl(pEthernet0, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	FlexGridSizer3->Add(tcEth0Mac, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(pEthernet0, ID_STATICTEXT16, _("IP Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	FlexGridSizer3->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth0Ip = new wxTextCtrl(pEthernet0, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	FlexGridSizer3->Add(tcEth0Ip, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText17 = new wxStaticText(pEthernet0, ID_STATICTEXT17, _("Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	FlexGridSizer3->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth0Mask = new wxTextCtrl(pEthernet0, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	FlexGridSizer3->Add(tcEth0Mask, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText18 = new wxStaticText(pEthernet0, ID_STATICTEXT18, _("Gateway"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	FlexGridSizer3->Add(StaticText18, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth0Gateway = new wxTextCtrl(pEthernet0, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	FlexGridSizer3->Add(tcEth0Gateway, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer12->Add(FlexGridSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	nbSocketEth0 = new wxNotebook(pEthernet0, ID_NOTEBOOK4, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK4"));
	pSocket0 = new wxPanel(nbSocketEth0, ID_PANEL13, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL13"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText19 = new wxStaticText(pSocket0, ID_STATICTEXT19, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	FlexGridSizer4->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket0Type = new wxChoice(pSocket0, ID_CHOICE5, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	chSocket0Type->SetSelection( chSocket0Type->Append(wxEmptyString) );
	chSocket0Type->Append(_("TCP Client"));
	chSocket0Type->Append(_("TCP Server"));
	chSocket0Type->Append(_("UDP"));
	chSocket0Type->Append(_("SCAP Client"));
	FlexGridSizer4->Add(chSocket0Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText20 = new wxStaticText(pSocket0, ID_STATICTEXT20, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	FlexGridSizer4->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket0DestIp = new wxTextCtrl(pSocket0, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	BoxSizer13->Add(tcSocket0DestIp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText23 = new wxStaticText(pSocket0, ID_STATICTEXT23, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	BoxSizer13->Add(StaticText23, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket0DestPort = new wxTextCtrl(pSocket0, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	BoxSizer13->Add(tcSocket0DestPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(BoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText21 = new wxStaticText(pSocket0, ID_STATICTEXT21, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	FlexGridSizer4->Add(StaticText21, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket0LocalPort = new wxTextCtrl(pSocket0, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	FlexGridSizer4->Add(tcSocket0LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText22 = new wxStaticText(pSocket0, ID_STATICTEXT22, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	FlexGridSizer4->Add(StaticText22, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket0Ndc = new wxCheckBox(pSocket0, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	cbSocket0Ndc->SetValue(false);
	FlexGridSizer4->Add(cbSocket0Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket0->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(pSocket0);
	FlexGridSizer4->SetSizeHints(pSocket0);
	pSocket1 = new wxPanel(nbSocketEth0, ID_PANEL14, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL14"));
	FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText24 = new wxStaticText(pSocket1, ID_STATICTEXT24, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	FlexGridSizer5->Add(StaticText24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket1Type = new wxChoice(pSocket1, ID_CHOICE6, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
	chSocket1Type->SetSelection( chSocket1Type->Append(wxEmptyString) );
	chSocket1Type->Append(_("TCP Client"));
	chSocket1Type->Append(_("TCP Server"));
	chSocket1Type->Append(_("UDP"));
	chSocket1Type->Append(_("SCAP Client"));
	FlexGridSizer5->Add(chSocket1Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText = new wxStaticText(pSocket1, ID_STATICTEXT25, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	FlexGridSizer5->Add(StaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket1DestIp = new wxTextCtrl(pSocket1, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	BoxSizer14->Add(tcSocket1DestIp, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText28 = new wxStaticText(pSocket1, ID_STATICTEXT28, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	BoxSizer14->Add(StaticText28, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket1DestPort = new wxTextCtrl(pSocket1, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	BoxSizer14->Add(tcSocket1DestPort, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(BoxSizer14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(pSocket1, ID_STATICTEXT26, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	FlexGridSizer5->Add(StaticText26, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket1LocalPort = new wxTextCtrl(pSocket1, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
	FlexGridSizer5->Add(tcSocket1LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText27 = new wxStaticText(pSocket1, ID_STATICTEXT27, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
	FlexGridSizer5->Add(StaticText27, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket1Ndc = new wxCheckBox(pSocket1, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	cbSocket1Ndc->SetValue(false);
	FlexGridSizer5->Add(cbSocket1Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket1->SetSizer(FlexGridSizer5);
	FlexGridSizer5->Fit(pSocket1);
	FlexGridSizer5->SetSizeHints(pSocket1);
	pSocket2 = new wxPanel(nbSocketEth0, ID_PANEL15, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL15"));
	FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText25 = new wxStaticText(pSocket2, ID_STATICTEXT29, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
	FlexGridSizer6->Add(StaticText25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket2Type = new wxChoice(pSocket2, ID_CHOICE7, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
	chSocket2Type->SetSelection( chSocket2Type->Append(wxEmptyString) );
	chSocket2Type->Append(_("TCP Client"));
	chSocket2Type->Append(_("TCP Server"));
	chSocket2Type->Append(_("UDP"));
	chSocket2Type->Append(_("SCAP Client"));
	FlexGridSizer6->Add(chSocket2Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText29 = new wxStaticText(pSocket2, ID_STATICTEXT30, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
	FlexGridSizer6->Add(StaticText29, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket2DestIp = new wxTextCtrl(pSocket2, ID_TEXTCTRL20, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
	BoxSizer15->Add(tcSocket2DestIp, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText32 = new wxStaticText(pSocket2, ID_STATICTEXT33, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
	BoxSizer15->Add(StaticText32, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket2DestPort = new wxTextCtrl(pSocket2, ID_TEXTCTRL21, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
	BoxSizer15->Add(tcSocket2DestPort, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(BoxSizer15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText30 = new wxStaticText(pSocket2, ID_STATICTEXT31, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
	FlexGridSizer6->Add(StaticText30, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket2LocalPort = new wxTextCtrl(pSocket2, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	FlexGridSizer6->Add(tcSocket2LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText31 = new wxStaticText(pSocket2, ID_STATICTEXT32, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
	FlexGridSizer6->Add(StaticText31, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket2Ndc = new wxCheckBox(pSocket2, ID_CHECKBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	cbSocket2Ndc->SetValue(false);
	FlexGridSizer6->Add(cbSocket2Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket2->SetSizer(FlexGridSizer6);
	FlexGridSizer6->Fit(pSocket2);
	FlexGridSizer6->SetSizeHints(pSocket2);
	pSocket3 = new wxPanel(nbSocketEth0, ID_PANEL16, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL16"));
	FlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText33 = new wxStaticText(pSocket3, ID_STATICTEXT34, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
	FlexGridSizer7->Add(StaticText33, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket3Type = new wxChoice(pSocket3, ID_CHOICE8, wxDefaultPosition, wxSize(139,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
	chSocket3Type->SetSelection( chSocket3Type->Append(wxEmptyString) );
	chSocket3Type->Append(_("TCP Client"));
	chSocket3Type->Append(_("TCP Server"));
	chSocket3Type->Append(_("UDP"));
	chSocket3Type->Append(_("SCAP Client"));
	FlexGridSizer7->Add(chSocket3Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText34 = new wxStaticText(pSocket3, ID_STATICTEXT35, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
	FlexGridSizer7->Add(StaticText34, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket3DestIp = new wxTextCtrl(pSocket3, ID_TEXTCTRL23, wxEmptyString, wxDefaultPosition, wxSize(134,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
	BoxSizer16->Add(tcSocket3DestIp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText37 = new wxStaticText(pSocket3, ID_STATICTEXT38, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
	BoxSizer16->Add(StaticText37, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket3DestPort = new wxTextCtrl(pSocket3, ID_TEXTCTRL24, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
	BoxSizer16->Add(tcSocket3DestPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(BoxSizer16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText35 = new wxStaticText(pSocket3, ID_STATICTEXT36, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
	FlexGridSizer7->Add(StaticText35, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket3LocalPort = new wxTextCtrl(pSocket3, ID_TEXTCTRL22, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
	FlexGridSizer7->Add(tcSocket3LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText36 = new wxStaticText(pSocket3, ID_STATICTEXT37, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
	FlexGridSizer7->Add(StaticText36, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket3Ndc = new wxCheckBox(pSocket3, ID_CHECKBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	cbSocket3Ndc->SetValue(false);
	FlexGridSizer7->Add(cbSocket3Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket3->SetSizer(FlexGridSizer7);
	FlexGridSizer7->Fit(pSocket3);
	FlexGridSizer7->SetSizeHints(pSocket3);
	nbSocketEth0->AddPage(pSocket0, _("Socket 0"), false);
	nbSocketEth0->AddPage(pSocket1, _("Socket 1"), false);
	nbSocketEth0->AddPage(pSocket2, _("Socket 2"), false);
	nbSocketEth0->AddPage(pSocket3, _("Socket 3"), false);
	BoxSizer12->Add(nbSocketEth0, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pEthernet0->SetSizer(BoxSizer12);
	BoxSizer12->Fit(pEthernet0);
	BoxSizer12->SetSizeHints(pEthernet0);
	pEthernet1 = new wxPanel(nbEthernet, ID_PANEL12, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL12"));
	BoxSizer17 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer8 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText38 = new wxStaticText(pEthernet1, ID_STATICTEXT39, _("MAC Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
	FlexGridSizer8->Add(StaticText38, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth1Mac = new wxTextCtrl(pEthernet1, ID_TEXTCTRL25, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
	FlexGridSizer8->Add(tcEth1Mac, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	IPAddress = new wxStaticText(pEthernet1, ID_STATICTEXT40, _("IP Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
	FlexGridSizer8->Add(IPAddress, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth1Ip = new wxTextCtrl(pEthernet1, ID_TEXTCTRL26, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
	FlexGridSizer8->Add(tcEth1Ip, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Mask = new wxStaticText(pEthernet1, ID_STATICTEXT41, _("Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
	FlexGridSizer8->Add(Mask, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth1Mask = new wxTextCtrl(pEthernet1, ID_TEXTCTRL27, wxEmptyString, wxDefaultPosition, wxSize(131,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
	FlexGridSizer8->Add(tcEth1Mask, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText41 = new wxStaticText(pEthernet1, ID_STATICTEXT42, _("Gateway"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
	FlexGridSizer8->Add(StaticText41, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcEth1Gateway = new wxTextCtrl(pEthernet1, ID_TEXTCTRL28, wxEmptyString, wxDefaultPosition, wxSize(112,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
	FlexGridSizer8->Add(tcEth1Gateway, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer17->Add(FlexGridSizer8, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	nbSocketEth1 = new wxNotebook(pEthernet1, ID_NOTEBOOK5, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK5"));
	pSocket4 = new wxPanel(nbSocketEth1, ID_PANEL17, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL17"));
	FlexGridSizer9 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText39 = new wxStaticText(pSocket4, ID_STATICTEXT43, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
	FlexGridSizer9->Add(StaticText39, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket4Type = new wxChoice(pSocket4, ID_CHOICE9, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
	chSocket4Type->SetSelection( chSocket4Type->Append(wxEmptyString) );
	chSocket4Type->Append(_("TCP Client"));
	chSocket4Type->Append(_("TCP Server"));
	chSocket4Type->Append(_("UDP"));
	chSocket4Type->Append(_("SCAP Client"));
	FlexGridSizer9->Add(chSocket4Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText40 = new wxStaticText(pSocket4, ID_STATICTEXT44, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
	FlexGridSizer9->Add(StaticText40, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket4DestIp = new wxTextCtrl(pSocket4, ID_TEXTCTRL30, wxEmptyString, wxDefaultPosition, wxSize(135,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
	BoxSizer18->Add(tcSocket4DestIp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText44 = new wxStaticText(pSocket4, ID_STATICTEXT47, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
	BoxSizer18->Add(StaticText44, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket4DestPort = new wxTextCtrl(pSocket4, ID_TEXTCTRL31, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));
	BoxSizer18->Add(tcSocket4DestPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(BoxSizer18, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText42 = new wxStaticText(pSocket4, ID_STATICTEXT45, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
	FlexGridSizer9->Add(StaticText42, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket4LocalPort = new wxTextCtrl(pSocket4, ID_TEXTCTRL29, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
	FlexGridSizer9->Add(tcSocket4LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText43 = new wxStaticText(pSocket4, ID_STATICTEXT46, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
	FlexGridSizer9->Add(StaticText43, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket4Ndc = new wxCheckBox(pSocket4, ID_CHECKBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	cbSocket4Ndc->SetValue(false);
	FlexGridSizer9->Add(cbSocket4Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket4->SetSizer(FlexGridSizer9);
	FlexGridSizer9->Fit(pSocket4);
	FlexGridSizer9->SetSizeHints(pSocket4);
	pSocket5 = new wxPanel(nbSocketEth1, ID_PANEL18, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL18"));
	FlexGridSizer10 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText45 = new wxStaticText(pSocket5, ID_STATICTEXT48, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
	FlexGridSizer10->Add(StaticText45, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket5Type = new wxChoice(pSocket5, ID_CHOICE10, wxDefaultPosition, wxSize(174,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE10"));
	chSocket5Type->SetSelection( chSocket5Type->Append(wxEmptyString) );
	chSocket5Type->Append(_("TCP Client"));
	chSocket5Type->Append(_("TCP Server"));
	chSocket5Type->Append(_("UDP"));
	chSocket5Type->Append(_("SCAP Client"));
	FlexGridSizer10->Add(chSocket5Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText46 = new wxStaticText(pSocket5, ID_STATICTEXT49, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
	FlexGridSizer10->Add(StaticText46, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket5DestIp = new wxTextCtrl(pSocket5, ID_TEXTCTRL33, wxEmptyString, wxDefaultPosition, wxSize(120,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL33"));
	BoxSizer19->Add(tcSocket5DestIp, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText49 = new wxStaticText(pSocket5, ID_STATICTEXT52, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
	BoxSizer19->Add(StaticText49, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket5DestPort = new wxTextCtrl(pSocket5, ID_TEXTCTRL34, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL34"));
	BoxSizer19->Add(tcSocket5DestPort, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(BoxSizer19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText47 = new wxStaticText(pSocket5, ID_STATICTEXT50, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
	FlexGridSizer10->Add(StaticText47, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket5LocalPort = new wxTextCtrl(pSocket5, ID_TEXTCTRL32, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL32"));
	FlexGridSizer10->Add(tcSocket5LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText48 = new wxStaticText(pSocket5, ID_STATICTEXT51, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
	FlexGridSizer10->Add(StaticText48, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket5Ndc = new wxCheckBox(pSocket5, ID_CHECKBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
	cbSocket5Ndc->SetValue(false);
	FlexGridSizer10->Add(cbSocket5Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket5->SetSizer(FlexGridSizer10);
	FlexGridSizer10->Fit(pSocket5);
	FlexGridSizer10->SetSizeHints(pSocket5);
	pSocket6 = new wxPanel(nbSocketEth1, ID_PANEL19, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL19"));
	FlexGridSizer11 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText50 = new wxStaticText(pSocket6, ID_STATICTEXT53, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
	FlexGridSizer11->Add(StaticText50, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket6Type = new wxChoice(pSocket6, ID_CHOICE11, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE11"));
	chSocket6Type->SetSelection( chSocket6Type->Append(wxEmptyString) );
	chSocket6Type->Append(_("TCP Client"));
	chSocket6Type->Append(_("TCP Server"));
	chSocket6Type->Append(_("UDP"));
	chSocket6Type->Append(_("SCAP Client"));
	FlexGridSizer11->Add(chSocket6Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText51 = new wxStaticText(pSocket6, ID_STATICTEXT54, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT54"));
	FlexGridSizer11->Add(StaticText51, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket6DestIp = new wxTextCtrl(pSocket6, ID_TEXTCTRL36, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL36"));
	BoxSizer20->Add(tcSocket6DestIp, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText54 = new wxStaticText(pSocket6, ID_STATICTEXT57, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT57"));
	BoxSizer20->Add(StaticText54, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket6DestPort = new wxTextCtrl(pSocket6, ID_TEXTCTRL37, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL37"));
	BoxSizer20->Add(tcSocket6DestPort, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer11->Add(BoxSizer20, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText52 = new wxStaticText(pSocket6, ID_STATICTEXT55, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT55"));
	FlexGridSizer11->Add(StaticText52, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket6LocalPort = new wxTextCtrl(pSocket6, ID_TEXTCTRL35, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL35"));
	FlexGridSizer11->Add(tcSocket6LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText53 = new wxStaticText(pSocket6, ID_STATICTEXT56, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT56"));
	FlexGridSizer11->Add(StaticText53, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket6Ndc = new wxCheckBox(pSocket6, ID_CHECKBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
	cbSocket6Ndc->SetValue(false);
	FlexGridSizer11->Add(cbSocket6Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket6->SetSizer(FlexGridSizer11);
	FlexGridSizer11->Fit(pSocket6);
	FlexGridSizer11->SetSizeHints(pSocket6);
	pSocket7 = new wxPanel(nbSocketEth1, ID_PANEL20, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL20"));
	FlexGridSizer12 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText55 = new wxStaticText(pSocket7, ID_STATICTEXT58, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT58"));
	FlexGridSizer12->Add(StaticText55, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chSocket7Type = new wxChoice(pSocket7, ID_CHOICE12, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE12"));
	chSocket7Type->SetSelection( chSocket7Type->Append(wxEmptyString) );
	chSocket7Type->Append(_("TCP Client"));
	chSocket7Type->Append(_("TCP Server"));
	chSocket7Type->Append(_("UDP"));
	chSocket7Type->Append(_("SCAP Client"));
	FlexGridSizer12->Add(chSocket7Type, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText56 = new wxStaticText(pSocket7, ID_STATICTEXT59, _("Dest IP:Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT59"));
	FlexGridSizer12->Add(StaticText56, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
	tcSocket7DestIp = new wxTextCtrl(pSocket7, ID_TEXTCTRL39, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL39"));
	BoxSizer21->Add(tcSocket7DestIp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText59 = new wxStaticText(pSocket7, ID_STATICTEXT62, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT62"));
	BoxSizer21->Add(StaticText59, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket7DestPort = new wxTextCtrl(pSocket7, ID_TEXTCTRL40, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL40"));
	BoxSizer21->Add(tcSocket7DestPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer12->Add(BoxSizer21, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText57 = new wxStaticText(pSocket7, ID_STATICTEXT60, _("Local Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT60"));
	FlexGridSizer12->Add(StaticText57, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcSocket7LocalPort = new wxTextCtrl(pSocket7, ID_TEXTCTRL38, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL38"));
	FlexGridSizer12->Add(tcSocket7LocalPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText58 = new wxStaticText(pSocket7, ID_STATICTEXT61, _("NDC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT61"));
	FlexGridSizer12->Add(StaticText58, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbSocket7Ndc = new wxCheckBox(pSocket7, ID_CHECKBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
	cbSocket7Ndc->SetValue(false);
	FlexGridSizer12->Add(cbSocket7Ndc, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pSocket7->SetSizer(FlexGridSizer12);
	FlexGridSizer12->Fit(pSocket7);
	FlexGridSizer12->SetSizeHints(pSocket7);
	nbSocketEth1->AddPage(pSocket4, _("Socket 4"), false);
	nbSocketEth1->AddPage(pSocket5, _("Socket 5"), false);
	nbSocketEth1->AddPage(pSocket6, _("Socket 6"), false);
	nbSocketEth1->AddPage(pSocket7, _("Socket 7"), false);
	BoxSizer17->Add(nbSocketEth1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pEthernet1->SetSizer(BoxSizer17);
	BoxSizer17->Fit(pEthernet1);
	BoxSizer17->SetSizeHints(pEthernet1);
	nbEthernet->AddPage(pEthernet0, _("Ethernet 0"), false);
	nbEthernet->AddPage(pEthernet1, _("Ethernet 1"), false);
	GridSizer2->Add(nbEthernet, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pEthernet->SetSizer(GridSizer2);
	GridSizer2->Fit(pEthernet);
	GridSizer2->SetSizeHints(pEthernet);
	pVch = new wxPanel(nbConfig, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL10"));
	GridSizer3 = new wxGridSizer(0, 1, 0, 0);
	nbVch = new wxNotebook(pVch, ID_NOTEBOOK6, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK6"));
	pVch1 = new wxPanel(nbVch, ID_PANEL21, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL21"));
	BoxSizer22 = new wxBoxSizer(wxVERTICAL);
	chVch1Switch = new wxChoice(pVch1, ID_CHOICE13, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE13"));
	chVch1Switch->SetSelection( chVch1Switch->Append(_("Disabled")) );
	chVch1Switch->Append(_("Enabled"));
	BoxSizer22->Add(chVch1Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer13 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer14 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText60 = new wxStaticText(pVch1, ID_STATICTEXT63, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT63"));
	FlexGridSizer14->Add(StaticText60, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch1WorkMode = new wxChoice(pVch1, ID_CHOICE14, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE14"));
	chVch1WorkMode->Append(_("Script"));
	chVch1WorkMode->Append(_("Any Data"));
	chVch1WorkMode->Append(_("Always Connected"));
	chVch1WorkMode->Append(_("Server"));
	FlexGridSizer14->Add(chVch1WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText61 = new wxStaticText(pVch1, ID_STATICTEXT64, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT64"));
	FlexGridSizer14->Add(StaticText61, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch1DefVipNum = new wxTextCtrl(pVch1, ID_TEXTCTRL41, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL41"));
	FlexGridSizer14->Add(tcVch1DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText62 = new wxStaticText(pVch1, ID_STATICTEXT65, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
	FlexGridSizer14->Add(StaticText62, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch1ScriptNum = new wxTextCtrl(pVch1, ID_TEXTCTRL42, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL42"));
	FlexGridSizer14->Add(tcVch1ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText63 = new wxStaticText(pVch1, ID_STATICTEXT66, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT66"));
	FlexGridSizer14->Add(StaticText63, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch1Interface = new wxTextCtrl(pVch1, ID_TEXTCTRL43, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL43"));
	FlexGridSizer14->Add(tcVch1Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText64 = new wxStaticText(pVch1, ID_STATICTEXT67, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT67"));
	FlexGridSizer14->Add(StaticText64, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch1Channel = new wxChoice(pVch1, ID_CHOICE15, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE15"));
	chVch1Channel->Append(wxEmptyString);
	chVch1Channel->Append(_("Socket 0"));
	chVch1Channel->Append(_("Socket 1"));
	chVch1Channel->Append(_("Socket 2"));
	chVch1Channel->Append(_("Socket 3"));
	chVch1Channel->Append(_("Socket 4"));
	chVch1Channel->Append(_("Socket 5"));
	chVch1Channel->Append(_("Socket 6"));
	chVch1Channel->Append(_("Socket 7"));
	FlexGridSizer14->Add(chVch1Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1RelayControl = new wxCheckBox(pVch1, ID_CHECKBOX18, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX18"));
	cbVch1RelayControl->SetValue(false);
	FlexGridSizer14->Add(cbVch1RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
	tcVch1RelayTime = new wxTextCtrl(pVch1, ID_TEXTCTRL47, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL47"));
	BoxSizer23->Add(tcVch1RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText74 = new wxStaticText(pVch1, ID_STATICTEXT77, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT77"));
	BoxSizer23->Add(StaticText74, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer14->Add(BoxSizer23, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer13->Add(FlexGridSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer15 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText65 = new wxStaticText(pVch1, ID_STATICTEXT68, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT68"));
	FlexGridSizer15->Add(StaticText65, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText66 = new wxStaticText(pVch1, ID_STATICTEXT69, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT69"));
	FlexGridSizer15->Add(StaticText66, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch1DelProto = new wxChoice(pVch1, ID_CHOICE16, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE16"));
	chVch1DelProto->SetSelection( chVch1DelProto->Append(_("Off")) );
	chVch1DelProto->Append(_("On"));
	FlexGridSizer15->Add(chVch1DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText67 = new wxStaticText(pVch1, ID_STATICTEXT70, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT70"));
	FlexGridSizer15->Add(StaticText67, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText68 = new wxStaticText(pVch1, ID_STATICTEXT71, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT71"));
	FlexGridSizer15->Add(StaticText68, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch1WndSize = new wxTextCtrl(pVch1, ID_TEXTCTRL44, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL44"));
	FlexGridSizer15->Add(tcVch1WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText69 = new wxStaticText(pVch1, ID_STATICTEXT72, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT72"));
	FlexGridSizer15->Add(StaticText69, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch1RetryCnt = new wxTextCtrl(pVch1, ID_TEXTCTRL45, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL45"));
	FlexGridSizer15->Add(tcVch1RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText70 = new wxStaticText(pVch1, ID_STATICTEXT73, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT73"));
	FlexGridSizer15->Add(StaticText70, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch1RetryTimeout = new wxTextCtrl(pVch1, ID_TEXTCTRL46, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL46"));
	FlexGridSizer15->Add(tcVch1RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer13->Add(FlexGridSizer15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer16 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText71 = new wxStaticText(pVch1, ID_STATICTEXT74, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT74"));
	FlexGridSizer16->Add(StaticText71, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText72 = new wxStaticText(pVch1, ID_STATICTEXT75, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT75"));
	FlexGridSizer16->Add(StaticText72, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1SerialPort = new wxCheckBox(pVch1, ID_CHECKBOX9, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
	cbVch1SerialPort->SetValue(false);
	FlexGridSizer16->Add(cbVch1SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText73 = new wxStaticText(pVch1, ID_STATICTEXT76, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT76"));
	FlexGridSizer16->Add(StaticText73, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket0 = new wxCheckBox(pVch1, ID_CHECKBOX10, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX10"));
	cbVch1Socket0->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket1 = new wxCheckBox(pVch1, ID_CHECKBOX11, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX11"));
	cbVch1Socket1->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket2 = new wxCheckBox(pVch1, ID_CHECKBOX12, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX12"));
	cbVch1Socket2->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket3 = new wxCheckBox(pVch1, ID_CHECKBOX13, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX13"));
	cbVch1Socket3->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket4 = new wxCheckBox(pVch1, ID_CHECKBOX14, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX14"));
	cbVch1Socket4->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket5 = new wxCheckBox(pVch1, ID_CHECKBOX15, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX15"));
	cbVch1Socket5->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket6 = new wxCheckBox(pVch1, ID_CHECKBOX16, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX16"));
	cbVch1Socket6->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch1Socket7 = new wxCheckBox(pVch1, ID_CHECKBOX17, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX17"));
	cbVch1Socket7->SetValue(false);
	FlexGridSizer16->Add(cbVch1Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer13->Add(FlexGridSizer16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer22->Add(FlexGridSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch1->SetSizer(BoxSizer22);
	BoxSizer22->Fit(pVch1);
	BoxSizer22->SetSizeHints(pVch1);
	pVch2 = new wxPanel(nbVch, ID_PANEL22, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL22"));
	BoxSizer24 = new wxBoxSizer(wxVERTICAL);
	chVch2Switch = new wxChoice(pVch2, ID_CHOICE17, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE17"));
	chVch2Switch->SetSelection( chVch2Switch->Append(_("Disabled")) );
	chVch2Switch->Append(_("Enabled"));
	BoxSizer24->Add(chVch2Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer17 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer18 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText75 = new wxStaticText(pVch2, ID_STATICTEXT78, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT78"));
	FlexGridSizer18->Add(StaticText75, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch2WorkMode = new wxChoice(pVch2, ID_CHOICE18, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE18"));
	chVch2WorkMode->Append(_("Script"));
	chVch2WorkMode->Append(_("Any Data"));
	chVch2WorkMode->Append(_("Always Connected"));
	chVch2WorkMode->Append(_("Server"));
	FlexGridSizer18->Add(chVch2WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText76 = new wxStaticText(pVch2, ID_STATICTEXT79, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT79"));
	FlexGridSizer18->Add(StaticText76, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch2DefVipNum = new wxTextCtrl(pVch2, ID_TEXTCTRL48, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL48"));
	FlexGridSizer18->Add(tcVch2DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText77 = new wxStaticText(pVch2, ID_STATICTEXT80, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT80"));
	FlexGridSizer18->Add(StaticText77, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch2ScriptNum = new wxTextCtrl(pVch2, ID_TEXTCTRL49, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL49"));
	FlexGridSizer18->Add(tcVch2ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText78 = new wxStaticText(pVch2, ID_STATICTEXT81, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT81"));
	FlexGridSizer18->Add(StaticText78, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch2Interface = new wxTextCtrl(pVch2, ID_TEXTCTRL50, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL50"));
	FlexGridSizer18->Add(tcVch2Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText79 = new wxStaticText(pVch2, ID_STATICTEXT82, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT82"));
	FlexGridSizer18->Add(StaticText79, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch2Channel = new wxChoice(pVch2, ID_CHOICE19, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE19"));
	chVch2Channel->Append(wxEmptyString);
	chVch2Channel->Append(_("Socket 0"));
	chVch2Channel->Append(_("Socket 1"));
	chVch2Channel->Append(_("Socket 2"));
	chVch2Channel->Append(_("Socket 3"));
	chVch2Channel->Append(_("Socket 4"));
	chVch2Channel->Append(_("Socket 5"));
	chVch2Channel->Append(_("Socket 6"));
	chVch2Channel->Append(_("Socket 7"));
	FlexGridSizer18->Add(chVch2Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2RelayControl = new wxCheckBox(pVch2, ID_CHECKBOX19, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX19"));
	cbVch2RelayControl->SetValue(false);
	FlexGridSizer18->Add(cbVch2RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer25 = new wxBoxSizer(wxHORIZONTAL);
	tcVch2RelayTime = new wxTextCtrl(pVch2, ID_TEXTCTRL51, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL51"));
	BoxSizer25->Add(tcVch2RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText80 = new wxStaticText(pVch2, ID_STATICTEXT83, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT83"));
	BoxSizer25->Add(StaticText80, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer18->Add(BoxSizer25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer17->Add(FlexGridSizer18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer19 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText81 = new wxStaticText(pVch2, ID_STATICTEXT84, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT84"));
	FlexGridSizer19->Add(StaticText81, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText82 = new wxStaticText(pVch2, ID_STATICTEXT85, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT85"));
	FlexGridSizer19->Add(StaticText82, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch2DelProto = new wxChoice(pVch2, ID_CHOICE20, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE20"));
	chVch2DelProto->SetSelection( chVch2DelProto->Append(_("Off")) );
	chVch2DelProto->Append(_("On"));
	FlexGridSizer19->Add(chVch2DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText83 = new wxStaticText(pVch2, ID_STATICTEXT86, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT86"));
	FlexGridSizer19->Add(StaticText83, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText84 = new wxStaticText(pVch2, ID_STATICTEXT87, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT87"));
	FlexGridSizer19->Add(StaticText84, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch2WndSize = new wxTextCtrl(pVch2, ID_TEXTCTRL52, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL52"));
	FlexGridSizer19->Add(tcVch2WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText85 = new wxStaticText(pVch2, ID_STATICTEXT88, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT88"));
	FlexGridSizer19->Add(StaticText85, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch2RetryCnt = new wxTextCtrl(pVch2, ID_TEXTCTRL53, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL53"));
	FlexGridSizer19->Add(tcVch2RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText86 = new wxStaticText(pVch2, ID_STATICTEXT89, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT89"));
	FlexGridSizer19->Add(StaticText86, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch2RetryTimeout = new wxTextCtrl(pVch2, ID_TEXTCTRL54, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL54"));
	FlexGridSizer19->Add(tcVch2RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer17->Add(FlexGridSizer19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer20 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText87 = new wxStaticText(pVch2, ID_STATICTEXT90, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT90"));
	FlexGridSizer20->Add(StaticText87, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText88 = new wxStaticText(pVch2, ID_STATICTEXT91, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT91"));
	FlexGridSizer20->Add(StaticText88, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2SerialPort = new wxCheckBox(pVch2, ID_CHECKBOX20, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX20"));
	cbVch2SerialPort->SetValue(false);
	FlexGridSizer20->Add(cbVch2SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText89 = new wxStaticText(pVch2, ID_STATICTEXT92, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT92"));
	FlexGridSizer20->Add(StaticText89, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket0 = new wxCheckBox(pVch2, ID_CHECKBOX21, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX21"));
	cbVch2Socket0->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket1 = new wxCheckBox(pVch2, ID_CHECKBOX22, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX22"));
	cbVch2Socket1->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket2 = new wxCheckBox(pVch2, ID_CHECKBOX23, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX23"));
	cbVch2Socket2->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket3 = new wxCheckBox(pVch2, ID_CHECKBOX24, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX24"));
	cbVch2Socket3->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket4 = new wxCheckBox(pVch2, ID_CHECKBOX25, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX25"));
	cbVch2Socket4->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket5 = new wxCheckBox(pVch2, ID_CHECKBOX26, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX26"));
	cbVch2Socket5->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket6 = new wxCheckBox(pVch2, ID_CHECKBOX27, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX27"));
	cbVch2Socket6->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch2Socket7 = new wxCheckBox(pVch2, ID_CHECKBOX28, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX28"));
	cbVch2Socket7->SetValue(false);
	FlexGridSizer20->Add(cbVch2Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer17->Add(FlexGridSizer20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer24->Add(FlexGridSizer17, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch2->SetSizer(BoxSizer24);
	BoxSizer24->Fit(pVch2);
	BoxSizer24->SetSizeHints(pVch2);
	pVch3 = new wxPanel(nbVch, ID_PANEL23, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL23"));
	BoxSizer26 = new wxBoxSizer(wxVERTICAL);
	chVch3Switch = new wxChoice(pVch3, ID_CHOICE21, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE21"));
	chVch3Switch->SetSelection( chVch3Switch->Append(_("Disabled")) );
	chVch3Switch->Append(_("Enabled"));
	BoxSizer26->Add(chVch3Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer21 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer22 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText90 = new wxStaticText(pVch3, ID_STATICTEXT93, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT93"));
	FlexGridSizer22->Add(StaticText90, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch3WorkMode = new wxChoice(pVch3, ID_CHOICE22, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE22"));
	chVch3WorkMode->Append(_("Script"));
	chVch3WorkMode->Append(_("Any Data"));
	chVch3WorkMode->Append(_("Always Connected"));
	chVch3WorkMode->Append(_("Server"));
	FlexGridSizer22->Add(chVch3WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText91 = new wxStaticText(pVch3, ID_STATICTEXT94, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT94"));
	FlexGridSizer22->Add(StaticText91, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch3DefVipNum = new wxTextCtrl(pVch3, ID_TEXTCTRL55, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL55"));
	FlexGridSizer22->Add(tcVch3DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText92 = new wxStaticText(pVch3, ID_STATICTEXT95, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT95"));
	FlexGridSizer22->Add(StaticText92, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch3ScriptNum = new wxTextCtrl(pVch3, ID_TEXTCTRL56, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL56"));
	FlexGridSizer22->Add(tcVch3ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText93 = new wxStaticText(pVch3, ID_STATICTEXT96, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT96"));
	FlexGridSizer22->Add(StaticText93, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch3Interface = new wxTextCtrl(pVch3, ID_TEXTCTRL57, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL57"));
	FlexGridSizer22->Add(tcVch3Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText94 = new wxStaticText(pVch3, ID_STATICTEXT97, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT97"));
	FlexGridSizer22->Add(StaticText94, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch3Channel = new wxChoice(pVch3, ID_CHOICE23, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE23"));
	chVch3Channel->Append(wxEmptyString);
	chVch3Channel->Append(_("Socket 0"));
	chVch3Channel->Append(_("Socket 1"));
	chVch3Channel->Append(_("Socket 2"));
	chVch3Channel->Append(_("Socket 3"));
	chVch3Channel->Append(_("Socket 4"));
	chVch3Channel->Append(_("Socket 5"));
	chVch3Channel->Append(_("Socket 6"));
	chVch3Channel->Append(_("Socket 7"));
	FlexGridSizer22->Add(chVch3Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3RelayControl = new wxCheckBox(pVch3, ID_CHECKBOX29, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX29"));
	cbVch3RelayControl->SetValue(false);
	FlexGridSizer22->Add(cbVch3RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
	tcVch3RelayTime = new wxTextCtrl(pVch3, ID_TEXTCTRL58, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL58"));
	BoxSizer27->Add(tcVch3RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText95 = new wxStaticText(pVch3, ID_STATICTEXT98, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT98"));
	BoxSizer27->Add(StaticText95, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer22->Add(BoxSizer27, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer21->Add(FlexGridSizer22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer23 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText96 = new wxStaticText(pVch3, ID_STATICTEXT99, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT99"));
	FlexGridSizer23->Add(StaticText96, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText97 = new wxStaticText(pVch3, ID_STATICTEXT100, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT100"));
	FlexGridSizer23->Add(StaticText97, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch3DelProto = new wxChoice(pVch3, ID_CHOICE24, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE24"));
	chVch3DelProto->SetSelection( chVch3DelProto->Append(_("Off")) );
	chVch3DelProto->Append(_("On"));
	FlexGridSizer23->Add(chVch3DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText98 = new wxStaticText(pVch3, ID_STATICTEXT101, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT101"));
	FlexGridSizer23->Add(StaticText98, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText99 = new wxStaticText(pVch3, ID_STATICTEXT102, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT102"));
	FlexGridSizer23->Add(StaticText99, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch3WndSize = new wxTextCtrl(pVch3, ID_TEXTCTRL59, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL59"));
	FlexGridSizer23->Add(tcVch3WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText100 = new wxStaticText(pVch3, ID_STATICTEXT103, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT103"));
	FlexGridSizer23->Add(StaticText100, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch3RetryCnt = new wxTextCtrl(pVch3, ID_TEXTCTRL60, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL60"));
	FlexGridSizer23->Add(tcVch3RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText101 = new wxStaticText(pVch3, ID_STATICTEXT104, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT104"));
	FlexGridSizer23->Add(StaticText101, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch3RetryTimeout = new wxTextCtrl(pVch3, ID_TEXTCTRL61, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL61"));
	FlexGridSizer23->Add(tcVch3RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer21->Add(FlexGridSizer23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer24 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText102 = new wxStaticText(pVch3, ID_STATICTEXT105, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT105"));
	FlexGridSizer24->Add(StaticText102, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText103 = new wxStaticText(pVch3, ID_STATICTEXT106, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT106"));
	FlexGridSizer24->Add(StaticText103, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3SerialPort = new wxCheckBox(pVch3, ID_CHECKBOX30, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX30"));
	cbVch3SerialPort->SetValue(false);
	FlexGridSizer24->Add(cbVch3SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText104 = new wxStaticText(pVch3, ID_STATICTEXT107, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT107"));
	FlexGridSizer24->Add(StaticText104, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket0 = new wxCheckBox(pVch3, ID_CHECKBOX31, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX31"));
	cbVch3Socket0->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket1 = new wxCheckBox(pVch3, ID_CHECKBOX32, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX32"));
	cbVch3Socket1->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket2 = new wxCheckBox(pVch3, ID_CHECKBOX33, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX33"));
	cbVch3Socket2->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket3 = new wxCheckBox(pVch3, ID_CHECKBOX34, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX34"));
	cbVch3Socket3->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket4 = new wxCheckBox(pVch3, ID_CHECKBOX35, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX35"));
	cbVch3Socket4->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket5 = new wxCheckBox(pVch3, ID_CHECKBOX36, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX36"));
	cbVch3Socket5->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket6 = new wxCheckBox(pVch3, ID_CHECKBOX37, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX37"));
	cbVch3Socket6->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch3Socket7 = new wxCheckBox(pVch3, ID_CHECKBOX38, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX38"));
	cbVch3Socket7->SetValue(false);
	FlexGridSizer24->Add(cbVch3Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer21->Add(FlexGridSizer24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer26->Add(FlexGridSizer21, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch3->SetSizer(BoxSizer26);
	BoxSizer26->Fit(pVch3);
	BoxSizer26->SetSizeHints(pVch3);
	pVch4 = new wxPanel(nbVch, ID_PANEL24, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL24"));
	BoxSizer28 = new wxBoxSizer(wxVERTICAL);
	chVch4Switch = new wxChoice(pVch4, ID_CHOICE25, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE25"));
	chVch4Switch->SetSelection( chVch4Switch->Append(_("Disabled")) );
	chVch4Switch->Append(_("Enabled"));
	BoxSizer28->Add(chVch4Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer25 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer26 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText105 = new wxStaticText(pVch4, ID_STATICTEXT108, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT108"));
	FlexGridSizer26->Add(StaticText105, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch4WorkMode = new wxChoice(pVch4, ID_CHOICE26, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE26"));
	chVch4WorkMode->Append(_("Script"));
	chVch4WorkMode->Append(_("Any Data"));
	chVch4WorkMode->Append(_("Always Connected"));
	chVch4WorkMode->Append(_("Server"));
	FlexGridSizer26->Add(chVch4WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText106 = new wxStaticText(pVch4, ID_STATICTEXT109, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT109"));
	FlexGridSizer26->Add(StaticText106, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch4DefVipNum = new wxTextCtrl(pVch4, ID_TEXTCTRL62, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL62"));
	FlexGridSizer26->Add(tcVch4DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText107 = new wxStaticText(pVch4, ID_STATICTEXT110, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT110"));
	FlexGridSizer26->Add(StaticText107, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch4ScriptNum = new wxTextCtrl(pVch4, ID_TEXTCTRL63, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL63"));
	FlexGridSizer26->Add(tcVch4ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText108 = new wxStaticText(pVch4, ID_STATICTEXT111, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT111"));
	FlexGridSizer26->Add(StaticText108, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch4Interface = new wxTextCtrl(pVch4, ID_TEXTCTRL64, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL64"));
	FlexGridSizer26->Add(tcVch4Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText109 = new wxStaticText(pVch4, ID_STATICTEXT112, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT112"));
	FlexGridSizer26->Add(StaticText109, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch4Channel = new wxChoice(pVch4, ID_CHOICE27, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE27"));
	chVch4Channel->Append(wxEmptyString);
	chVch4Channel->Append(_("Socket 0"));
	chVch4Channel->Append(_("Socket 1"));
	chVch4Channel->Append(_("Socket 2"));
	chVch4Channel->Append(_("Socket 3"));
	chVch4Channel->Append(_("Socket 4"));
	chVch4Channel->Append(_("Socket 5"));
	chVch4Channel->Append(_("Socket 6"));
	chVch4Channel->Append(_("Socket 7"));
	FlexGridSizer26->Add(chVch4Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4RelayControl = new wxCheckBox(pVch4, ID_CHECKBOX39, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX39"));
	cbVch4RelayControl->SetValue(false);
	FlexGridSizer26->Add(cbVch4RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
	tcVch4RelayTime = new wxTextCtrl(pVch4, ID_TEXTCTRL65, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL65"));
	BoxSizer29->Add(tcVch4RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText110 = new wxStaticText(pVch4, ID_STATICTEXT113, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT113"));
	BoxSizer29->Add(StaticText110, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer26->Add(BoxSizer29, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer25->Add(FlexGridSizer26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer27 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText111 = new wxStaticText(pVch4, ID_STATICTEXT114, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT114"));
	FlexGridSizer27->Add(StaticText111, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText112 = new wxStaticText(pVch4, ID_STATICTEXT115, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT115"));
	FlexGridSizer27->Add(StaticText112, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch4DelProto = new wxChoice(pVch4, ID_CHOICE28, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE28"));
	chVch4DelProto->SetSelection( chVch4DelProto->Append(_("Off")) );
	chVch4DelProto->Append(_("On"));
	FlexGridSizer27->Add(chVch4DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText113 = new wxStaticText(pVch4, ID_STATICTEXT116, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT116"));
	FlexGridSizer27->Add(StaticText113, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText114 = new wxStaticText(pVch4, ID_STATICTEXT117, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT117"));
	FlexGridSizer27->Add(StaticText114, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch4WndSize = new wxTextCtrl(pVch4, ID_TEXTCTRL66, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL66"));
	FlexGridSizer27->Add(tcVch4WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText115 = new wxStaticText(pVch4, ID_STATICTEXT118, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT118"));
	FlexGridSizer27->Add(StaticText115, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch4RetryCnt = new wxTextCtrl(pVch4, ID_TEXTCTRL67, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL67"));
	FlexGridSizer27->Add(tcVch4RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText116 = new wxStaticText(pVch4, ID_STATICTEXT119, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT119"));
	FlexGridSizer27->Add(StaticText116, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch4RetryTimeout = new wxTextCtrl(pVch4, ID_TEXTCTRL68, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL68"));
	FlexGridSizer27->Add(tcVch4RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer25->Add(FlexGridSizer27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer28 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText117 = new wxStaticText(pVch4, ID_STATICTEXT120, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT120"));
	FlexGridSizer28->Add(StaticText117, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText118 = new wxStaticText(pVch4, ID_STATICTEXT121, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT121"));
	FlexGridSizer28->Add(StaticText118, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4SerialPort = new wxCheckBox(pVch4, ID_CHECKBOX40, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX40"));
	cbVch4SerialPort->SetValue(false);
	FlexGridSizer28->Add(cbVch4SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText119 = new wxStaticText(pVch4, ID_STATICTEXT122, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT122"));
	FlexGridSizer28->Add(StaticText119, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket0 = new wxCheckBox(pVch4, ID_CHECKBOX41, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX41"));
	cbVch4Socket0->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket1 = new wxCheckBox(pVch4, ID_CHECKBOX42, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX42"));
	cbVch4Socket1->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket2 = new wxCheckBox(pVch4, ID_CHECKBOX43, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX43"));
	cbVch4Socket2->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket3 = new wxCheckBox(pVch4, ID_CHECKBOX44, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX44"));
	cbVch4Socket3->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket4 = new wxCheckBox(pVch4, ID_CHECKBOX45, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX45"));
	cbVch4Socket4->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket5 = new wxCheckBox(pVch4, ID_CHECKBOX46, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX46"));
	cbVch4Socket5->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket6 = new wxCheckBox(pVch4, ID_CHECKBOX47, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX47"));
	cbVch4Socket6->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch4Socket7 = new wxCheckBox(pVch4, ID_CHECKBOX48, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX48"));
	cbVch4Socket7->SetValue(false);
	FlexGridSizer28->Add(cbVch4Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer25->Add(FlexGridSizer28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer28->Add(FlexGridSizer25, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch4->SetSizer(BoxSizer28);
	BoxSizer28->Fit(pVch4);
	BoxSizer28->SetSizeHints(pVch4);
	pVch5 = new wxPanel(nbVch, ID_PANEL25, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL25"));
	BoxSizer30 = new wxBoxSizer(wxVERTICAL);
	chVch5Switch = new wxChoice(pVch5, ID_CHOICE29, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE29"));
	chVch5Switch->SetSelection( chVch5Switch->Append(_("Disabled")) );
	chVch5Switch->Append(_("Enabled"));
	BoxSizer30->Add(chVch5Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer29 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer30 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText120 = new wxStaticText(pVch5, ID_STATICTEXT123, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT123"));
	FlexGridSizer30->Add(StaticText120, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch5WorkMode = new wxChoice(pVch5, ID_CHOICE30, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE30"));
	chVch5WorkMode->Append(_("Script"));
	chVch5WorkMode->Append(_("Any Data"));
	chVch5WorkMode->Append(_("Always Connected"));
	chVch5WorkMode->Append(_("Server"));
	FlexGridSizer30->Add(chVch5WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText121 = new wxStaticText(pVch5, ID_STATICTEXT124, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT124"));
	FlexGridSizer30->Add(StaticText121, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch5DefVipNum = new wxTextCtrl(pVch5, ID_TEXTCTRL69, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL69"));
	FlexGridSizer30->Add(tcVch5DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText122 = new wxStaticText(pVch5, ID_STATICTEXT125, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT125"));
	FlexGridSizer30->Add(StaticText122, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch5ScriptNum = new wxTextCtrl(pVch5, ID_TEXTCTRL70, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL70"));
	FlexGridSizer30->Add(tcVch5ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText123 = new wxStaticText(pVch5, ID_STATICTEXT126, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT126"));
	FlexGridSizer30->Add(StaticText123, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch5Interface = new wxTextCtrl(pVch5, ID_TEXTCTRL71, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL71"));
	FlexGridSizer30->Add(tcVch5Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText124 = new wxStaticText(pVch5, ID_STATICTEXT127, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT127"));
	FlexGridSizer30->Add(StaticText124, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch5Channel = new wxChoice(pVch5, ID_CHOICE31, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE31"));
	chVch5Channel->Append(wxEmptyString);
	chVch5Channel->Append(_("Socket 0"));
	chVch5Channel->Append(_("Socket 1"));
	chVch5Channel->Append(_("Socket 2"));
	chVch5Channel->Append(_("Socket 3"));
	chVch5Channel->Append(_("Socket 4"));
	chVch5Channel->Append(_("Socket 5"));
	chVch5Channel->Append(_("Socket 6"));
	chVch5Channel->Append(_("Socket 7"));
	FlexGridSizer30->Add(chVch5Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5RelayControl = new wxCheckBox(pVch5, ID_CHECKBOX49, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX49"));
	cbVch5RelayControl->SetValue(false);
	FlexGridSizer30->Add(cbVch5RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
	tcVch5RelayTime = new wxTextCtrl(pVch5, ID_TEXTCTRL72, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL72"));
	BoxSizer31->Add(tcVch5RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText125 = new wxStaticText(pVch5, ID_STATICTEXT128, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT128"));
	BoxSizer31->Add(StaticText125, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer30->Add(BoxSizer31, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer29->Add(FlexGridSizer30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer31 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText126 = new wxStaticText(pVch5, ID_STATICTEXT129, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT129"));
	FlexGridSizer31->Add(StaticText126, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText127 = new wxStaticText(pVch5, ID_STATICTEXT130, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT130"));
	FlexGridSizer31->Add(StaticText127, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch5DelProto = new wxChoice(pVch5, ID_CHOICE32, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE32"));
	chVch5DelProto->SetSelection( chVch5DelProto->Append(_("Off")) );
	chVch5DelProto->Append(_("On"));
	FlexGridSizer31->Add(chVch5DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText128 = new wxStaticText(pVch5, ID_STATICTEXT131, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT131"));
	FlexGridSizer31->Add(StaticText128, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText129 = new wxStaticText(pVch5, ID_STATICTEXT132, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT132"));
	FlexGridSizer31->Add(StaticText129, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch5WndSize = new wxTextCtrl(pVch5, ID_TEXTCTRL73, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL73"));
	FlexGridSizer31->Add(tcVch5WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText130 = new wxStaticText(pVch5, ID_STATICTEXT133, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT133"));
	FlexGridSizer31->Add(StaticText130, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch5RetryCnt = new wxTextCtrl(pVch5, ID_TEXTCTRL74, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL74"));
	FlexGridSizer31->Add(tcVch5RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText131 = new wxStaticText(pVch5, ID_STATICTEXT134, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT134"));
	FlexGridSizer31->Add(StaticText131, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch5RetryTimeout = new wxTextCtrl(pVch5, ID_TEXTCTRL75, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL75"));
	FlexGridSizer31->Add(tcVch5RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer29->Add(FlexGridSizer31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer32 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText132 = new wxStaticText(pVch5, ID_STATICTEXT135, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT135"));
	FlexGridSizer32->Add(StaticText132, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText133 = new wxStaticText(pVch5, ID_STATICTEXT136, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT136"));
	FlexGridSizer32->Add(StaticText133, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5SerialPort = new wxCheckBox(pVch5, ID_CHECKBOX50, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX50"));
	cbVch5SerialPort->SetValue(false);
	FlexGridSizer32->Add(cbVch5SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText134 = new wxStaticText(pVch5, ID_STATICTEXT137, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT137"));
	FlexGridSizer32->Add(StaticText134, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket0 = new wxCheckBox(pVch5, ID_CHECKBOX51, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX51"));
	cbVch5Socket0->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket1 = new wxCheckBox(pVch5, ID_CHECKBOX52, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX52"));
	cbVch5Socket1->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket2 = new wxCheckBox(pVch5, ID_CHECKBOX53, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX53"));
	cbVch5Socket2->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket3 = new wxCheckBox(pVch5, ID_CHECKBOX54, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX54"));
	cbVch5Socket3->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket4 = new wxCheckBox(pVch5, ID_CHECKBOX55, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX55"));
	cbVch5Socket4->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket5 = new wxCheckBox(pVch5, ID_CHECKBOX56, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX56"));
	cbVch5Socket5->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket6 = new wxCheckBox(pVch5, ID_CHECKBOX57, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX57"));
	cbVch5Socket6->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch5Socket7 = new wxCheckBox(pVch5, ID_CHECKBOX58, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX58"));
	cbVch5Socket7->SetValue(false);
	FlexGridSizer32->Add(cbVch5Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer29->Add(FlexGridSizer32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer30->Add(FlexGridSizer29, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch5->SetSizer(BoxSizer30);
	BoxSizer30->Fit(pVch5);
	BoxSizer30->SetSizeHints(pVch5);
	pVch6 = new wxPanel(nbVch, ID_PANEL26, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL26"));
	BoxSizer32 = new wxBoxSizer(wxVERTICAL);
	chVch6Switch = new wxChoice(pVch6, ID_CHOICE33, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE33"));
	chVch6Switch->SetSelection( chVch6Switch->Append(_("Disabled")) );
	chVch6Switch->Append(_("Enabled"));
	BoxSizer32->Add(chVch6Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer33 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer34 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText135 = new wxStaticText(pVch6, ID_STATICTEXT138, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT138"));
	FlexGridSizer34->Add(StaticText135, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch6WorkMode = new wxChoice(pVch6, ID_CHOICE34, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE34"));
	chVch6WorkMode->Append(_("Script"));
	chVch6WorkMode->Append(_("Any Data"));
	chVch6WorkMode->Append(_("Always Connected"));
	chVch6WorkMode->Append(_("Server"));
	FlexGridSizer34->Add(chVch6WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText136 = new wxStaticText(pVch6, ID_STATICTEXT139, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT139"));
	FlexGridSizer34->Add(StaticText136, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch6DefVipNum = new wxTextCtrl(pVch6, ID_TEXTCTRL76, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL76"));
	FlexGridSizer34->Add(tcVch6DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText137 = new wxStaticText(pVch6, ID_STATICTEXT140, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT140"));
	FlexGridSizer34->Add(StaticText137, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch6ScriptNum = new wxTextCtrl(pVch6, ID_TEXTCTRL77, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL77"));
	FlexGridSizer34->Add(tcVch6ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText138 = new wxStaticText(pVch6, ID_STATICTEXT141, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT141"));
	FlexGridSizer34->Add(StaticText138, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch6Interface = new wxTextCtrl(pVch6, ID_TEXTCTRL78, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL78"));
	FlexGridSizer34->Add(tcVch6Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText139 = new wxStaticText(pVch6, ID_STATICTEXT142, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT142"));
	FlexGridSizer34->Add(StaticText139, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch6Channel = new wxChoice(pVch6, ID_CHOICE35, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE35"));
	chVch6Channel->Append(wxEmptyString);
	chVch6Channel->Append(_("Socket 0"));
	chVch6Channel->Append(_("Socket 1"));
	chVch6Channel->Append(_("Socket 2"));
	chVch6Channel->Append(_("Socket 3"));
	chVch6Channel->Append(_("Socket 4"));
	chVch6Channel->Append(_("Socket 5"));
	chVch6Channel->Append(_("Socket 6"));
	chVch6Channel->Append(_("Socket 7"));
	FlexGridSizer34->Add(chVch6Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6RelayControl = new wxCheckBox(pVch6, ID_CHECKBOX59, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX59"));
	cbVch6RelayControl->SetValue(false);
	FlexGridSizer34->Add(cbVch6RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer33 = new wxBoxSizer(wxHORIZONTAL);
	tcVch6RelayTime = new wxTextCtrl(pVch6, ID_TEXTCTRL79, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL79"));
	BoxSizer33->Add(tcVch6RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText140 = new wxStaticText(pVch6, ID_STATICTEXT143, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT143"));
	BoxSizer33->Add(StaticText140, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer34->Add(BoxSizer33, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer33->Add(FlexGridSizer34, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer35 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText141 = new wxStaticText(pVch6, ID_STATICTEXT144, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT144"));
	FlexGridSizer35->Add(StaticText141, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText142 = new wxStaticText(pVch6, ID_STATICTEXT145, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT145"));
	FlexGridSizer35->Add(StaticText142, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch6DelProto = new wxChoice(pVch6, ID_CHOICE36, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE36"));
	chVch6DelProto->SetSelection( chVch6DelProto->Append(_("Off")) );
	chVch6DelProto->Append(_("On"));
	FlexGridSizer35->Add(chVch6DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText143 = new wxStaticText(pVch6, ID_STATICTEXT146, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT146"));
	FlexGridSizer35->Add(StaticText143, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText144 = new wxStaticText(pVch6, ID_STATICTEXT147, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT147"));
	FlexGridSizer35->Add(StaticText144, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch6WndSize = new wxTextCtrl(pVch6, ID_TEXTCTRL80, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL80"));
	FlexGridSizer35->Add(tcVch6WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText145 = new wxStaticText(pVch6, ID_STATICTEXT148, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT148"));
	FlexGridSizer35->Add(StaticText145, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch6RetryCnt = new wxTextCtrl(pVch6, ID_TEXTCTRL81, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL81"));
	FlexGridSizer35->Add(tcVch6RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText146 = new wxStaticText(pVch6, ID_STATICTEXT149, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT149"));
	FlexGridSizer35->Add(StaticText146, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch6RetryTimeout = new wxTextCtrl(pVch6, ID_TEXTCTRL82, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL82"));
	FlexGridSizer35->Add(tcVch6RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer33->Add(FlexGridSizer35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer36 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText147 = new wxStaticText(pVch6, ID_STATICTEXT150, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT150"));
	FlexGridSizer36->Add(StaticText147, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText148 = new wxStaticText(pVch6, ID_STATICTEXT151, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT151"));
	FlexGridSizer36->Add(StaticText148, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6SerialPort = new wxCheckBox(pVch6, ID_CHECKBOX60, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX60"));
	cbVch6SerialPort->SetValue(false);
	FlexGridSizer36->Add(cbVch6SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText149 = new wxStaticText(pVch6, ID_STATICTEXT152, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT152"));
	FlexGridSizer36->Add(StaticText149, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket0 = new wxCheckBox(pVch6, ID_CHECKBOX61, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX61"));
	cbVch6Socket0->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket1 = new wxCheckBox(pVch6, ID_CHECKBOX62, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX62"));
	cbVch6Socket1->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket2 = new wxCheckBox(pVch6, ID_CHECKBOX63, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX63"));
	cbVch6Socket2->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket3 = new wxCheckBox(pVch6, ID_CHECKBOX64, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX64"));
	cbVch6Socket3->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket4 = new wxCheckBox(pVch6, ID_CHECKBOX65, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX65"));
	cbVch6Socket4->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket5 = new wxCheckBox(pVch6, ID_CHECKBOX66, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX66"));
	cbVch6Socket5->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket6 = new wxCheckBox(pVch6, ID_CHECKBOX67, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX67"));
	cbVch6Socket6->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch6Socket7 = new wxCheckBox(pVch6, ID_CHECKBOX68, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX68"));
	cbVch6Socket7->SetValue(false);
	FlexGridSizer36->Add(cbVch6Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer33->Add(FlexGridSizer36, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer32->Add(FlexGridSizer33, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch6->SetSizer(BoxSizer32);
	BoxSizer32->Fit(pVch6);
	BoxSizer32->SetSizeHints(pVch6);
	pVch7 = new wxPanel(nbVch, ID_PANEL27, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL27"));
	BoxSizer34 = new wxBoxSizer(wxVERTICAL);
	chVch7Switch = new wxChoice(pVch7, ID_CHOICE37, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE37"));
	chVch7Switch->SetSelection( chVch7Switch->Append(_("Disabled")) );
	chVch7Switch->Append(_("Enabled"));
	BoxSizer34->Add(chVch7Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer37 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer38 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText150 = new wxStaticText(pVch7, ID_STATICTEXT153, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT153"));
	FlexGridSizer38->Add(StaticText150, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch7WorkMode = new wxChoice(pVch7, ID_CHOICE38, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE38"));
	chVch7WorkMode->Append(_("Script"));
	chVch7WorkMode->Append(_("Any Data"));
	chVch7WorkMode->Append(_("Always Connected"));
	chVch7WorkMode->Append(_("Server"));
	FlexGridSizer38->Add(chVch7WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText151 = new wxStaticText(pVch7, ID_STATICTEXT154, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT154"));
	FlexGridSizer38->Add(StaticText151, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch7DefVipNum = new wxTextCtrl(pVch7, ID_TEXTCTRL83, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL83"));
	FlexGridSizer38->Add(tcVch7DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText152 = new wxStaticText(pVch7, ID_STATICTEXT155, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT155"));
	FlexGridSizer38->Add(StaticText152, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch7ScriptNum = new wxTextCtrl(pVch7, ID_TEXTCTRL84, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL84"));
	FlexGridSizer38->Add(tcVch7ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText153 = new wxStaticText(pVch7, ID_STATICTEXT156, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT156"));
	FlexGridSizer38->Add(StaticText153, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch7Interface = new wxTextCtrl(pVch7, ID_TEXTCTRL85, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL85"));
	FlexGridSizer38->Add(tcVch7Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText154 = new wxStaticText(pVch7, ID_STATICTEXT157, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT157"));
	FlexGridSizer38->Add(StaticText154, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch7Channel = new wxChoice(pVch7, ID_CHOICE39, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE39"));
	chVch7Channel->Append(wxEmptyString);
	chVch7Channel->Append(_("Socket 0"));
	chVch7Channel->Append(_("Socket 1"));
	chVch7Channel->Append(_("Socket 2"));
	chVch7Channel->Append(_("Socket 3"));
	chVch7Channel->Append(_("Socket 4"));
	chVch7Channel->Append(_("Socket 5"));
	chVch7Channel->Append(_("Socket 6"));
	chVch7Channel->Append(_("Socket 7"));
	FlexGridSizer38->Add(chVch7Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7RelayControl = new wxCheckBox(pVch7, ID_CHECKBOX69, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX69"));
	cbVch7RelayControl->SetValue(false);
	FlexGridSizer38->Add(cbVch7RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer35 = new wxBoxSizer(wxHORIZONTAL);
	tcVch7RelayTime = new wxTextCtrl(pVch7, ID_TEXTCTRL86, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL86"));
	BoxSizer35->Add(tcVch7RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText155 = new wxStaticText(pVch7, ID_STATICTEXT158, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT158"));
	BoxSizer35->Add(StaticText155, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer38->Add(BoxSizer35, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer37->Add(FlexGridSizer38, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer39 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText156 = new wxStaticText(pVch7, ID_STATICTEXT159, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT159"));
	FlexGridSizer39->Add(StaticText156, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText157 = new wxStaticText(pVch7, ID_STATICTEXT160, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT160"));
	FlexGridSizer39->Add(StaticText157, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch7DelProto = new wxChoice(pVch7, ID_CHOICE40, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE40"));
	chVch7DelProto->SetSelection( chVch7DelProto->Append(_("Off")) );
	chVch7DelProto->Append(_("On"));
	FlexGridSizer39->Add(chVch7DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText158 = new wxStaticText(pVch7, ID_STATICTEXT161, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT161"));
	FlexGridSizer39->Add(StaticText158, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText159 = new wxStaticText(pVch7, ID_STATICTEXT162, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT162"));
	FlexGridSizer39->Add(StaticText159, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch7WndSize = new wxTextCtrl(pVch7, ID_TEXTCTRL87, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL87"));
	FlexGridSizer39->Add(tcVch7WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText160 = new wxStaticText(pVch7, ID_STATICTEXT163, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT163"));
	FlexGridSizer39->Add(StaticText160, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch7RetryCnt = new wxTextCtrl(pVch7, ID_TEXTCTRL88, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL88"));
	FlexGridSizer39->Add(tcVch7RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText161 = new wxStaticText(pVch7, ID_STATICTEXT164, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT164"));
	FlexGridSizer39->Add(StaticText161, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch7RetryTimeout = new wxTextCtrl(pVch7, ID_TEXTCTRL89, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL89"));
	FlexGridSizer39->Add(tcVch7RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer37->Add(FlexGridSizer39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer40 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText162 = new wxStaticText(pVch7, ID_STATICTEXT165, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT165"));
	FlexGridSizer40->Add(StaticText162, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText163 = new wxStaticText(pVch7, ID_STATICTEXT166, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT166"));
	FlexGridSizer40->Add(StaticText163, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7SerialPort = new wxCheckBox(pVch7, ID_CHECKBOX70, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX70"));
	cbVch7SerialPort->SetValue(false);
	FlexGridSizer40->Add(cbVch7SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText164 = new wxStaticText(pVch7, ID_STATICTEXT167, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT167"));
	FlexGridSizer40->Add(StaticText164, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket0 = new wxCheckBox(pVch7, ID_CHECKBOX71, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX71"));
	cbVch7Socket0->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket1 = new wxCheckBox(pVch7, ID_CHECKBOX72, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX72"));
	cbVch7Socket1->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket2 = new wxCheckBox(pVch7, ID_CHECKBOX73, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX73"));
	cbVch7Socket2->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket3 = new wxCheckBox(pVch7, ID_CHECKBOX74, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX74"));
	cbVch7Socket3->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket4 = new wxCheckBox(pVch7, ID_CHECKBOX75, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX75"));
	cbVch7Socket4->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket5 = new wxCheckBox(pVch7, ID_CHECKBOX76, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX76"));
	cbVch7Socket5->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket6 = new wxCheckBox(pVch7, ID_CHECKBOX77, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX77"));
	cbVch7Socket6->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch7Socket7 = new wxCheckBox(pVch7, ID_CHECKBOX78, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX78"));
	cbVch7Socket7->SetValue(false);
	FlexGridSizer40->Add(cbVch7Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer37->Add(FlexGridSizer40, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer34->Add(FlexGridSizer37, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch7->SetSizer(BoxSizer34);
	BoxSizer34->Fit(pVch7);
	BoxSizer34->SetSizeHints(pVch7);
	pVch8 = new wxPanel(nbVch, ID_PANEL28, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL28"));
	BoxSizer36 = new wxBoxSizer(wxVERTICAL);
	chVch8Switch = new wxChoice(pVch8, ID_CHOICE41, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE41"));
	chVch8Switch->SetSelection( chVch8Switch->Append(_("Disabled")) );
	chVch8Switch->Append(_("Enabled"));
	BoxSizer36->Add(chVch8Switch, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer41 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer42 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText165 = new wxStaticText(pVch8, ID_STATICTEXT168, _("Work Mode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT168"));
	FlexGridSizer42->Add(StaticText165, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch8WorkMode = new wxChoice(pVch8, ID_CHOICE42, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE42"));
	chVch8WorkMode->Append(_("Script"));
	chVch8WorkMode->Append(_("Any Data"));
	chVch8WorkMode->Append(_("Always Connected"));
	chVch8WorkMode->Append(_("Server"));
	FlexGridSizer42->Add(chVch8WorkMode, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText166 = new wxStaticText(pVch8, ID_STATICTEXT169, _("Default VIP Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT169"));
	FlexGridSizer42->Add(StaticText166, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch8DefVipNum = new wxTextCtrl(pVch8, ID_TEXTCTRL90, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL90"));
	FlexGridSizer42->Add(tcVch8DefVipNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText167 = new wxStaticText(pVch8, ID_STATICTEXT170, _("Script Number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT170"));
	FlexGridSizer42->Add(StaticText167, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch8ScriptNum = new wxTextCtrl(pVch8, ID_TEXTCTRL91, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL91"));
	FlexGridSizer42->Add(tcVch8ScriptNum, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText168 = new wxStaticText(pVch8, ID_STATICTEXT171, _("Interface"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT171"));
	FlexGridSizer42->Add(StaticText168, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch8Interface = new wxTextCtrl(pVch8, ID_TEXTCTRL92, wxEmptyString, wxDefaultPosition, wxSize(140,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL92"));
	FlexGridSizer42->Add(tcVch8Interface, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText169 = new wxStaticText(pVch8, ID_STATICTEXT172, _("Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT172"));
	FlexGridSizer42->Add(StaticText169, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	chVch8Channel = new wxChoice(pVch8, ID_CHOICE43, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE43"));
	chVch8Channel->Append(wxEmptyString);
	chVch8Channel->Append(_("Socket 0"));
	chVch8Channel->Append(_("Socket 1"));
	chVch8Channel->Append(_("Socket 2"));
	chVch8Channel->Append(_("Socket 3"));
	chVch8Channel->Append(_("Socket 4"));
	chVch8Channel->Append(_("Socket 5"));
	chVch8Channel->Append(_("Socket 6"));
	chVch8Channel->Append(_("Socket 7"));
	FlexGridSizer42->Add(chVch8Channel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8RelayControl = new wxCheckBox(pVch8, ID_CHECKBOX79, _("Relay Control"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX79"));
	cbVch8RelayControl->SetValue(false);
	FlexGridSizer42->Add(cbVch8RelayControl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer37 = new wxBoxSizer(wxHORIZONTAL);
	tcVch8RelayTime = new wxTextCtrl(pVch8, ID_TEXTCTRL93, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL93"));
	BoxSizer37->Add(tcVch8RelayTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText170 = new wxStaticText(pVch8, ID_STATICTEXT173, _("sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT173"));
	BoxSizer37->Add(StaticText170, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer42->Add(BoxSizer37, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer41->Add(FlexGridSizer42, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer43 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText171 = new wxStaticText(pVch8, ID_STATICTEXT174, _("Delivery Protocol"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT174"));
	FlexGridSizer43->Add(StaticText171, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText172 = new wxStaticText(pVch8, ID_STATICTEXT175, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT175"));
	FlexGridSizer43->Add(StaticText172, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chVch8DelProto = new wxChoice(pVch8, ID_CHOICE44, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE44"));
	chVch8DelProto->SetSelection( chVch8DelProto->Append(_("Off")) );
	chVch8DelProto->Append(_("On"));
	FlexGridSizer43->Add(chVch8DelProto, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText173 = new wxStaticText(pVch8, ID_STATICTEXT176, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT176"));
	FlexGridSizer43->Add(StaticText173, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText174 = new wxStaticText(pVch8, ID_STATICTEXT177, _("Wnd Size, bytes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT177"));
	FlexGridSizer43->Add(StaticText174, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch8WndSize = new wxTextCtrl(pVch8, ID_TEXTCTRL94, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL94"));
	FlexGridSizer43->Add(tcVch8WndSize, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText175 = new wxStaticText(pVch8, ID_STATICTEXT178, _("Retry Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT178"));
	FlexGridSizer43->Add(StaticText175, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch8RetryCnt = new wxTextCtrl(pVch8, ID_TEXTCTRL95, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL95"));
	FlexGridSizer43->Add(tcVch8RetryCnt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText176 = new wxStaticText(pVch8, ID_STATICTEXT179, _("Retry Timeout, sec"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT179"));
	FlexGridSizer43->Add(StaticText176, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tcVch8RetryTimeout = new wxTextCtrl(pVch8, ID_TEXTCTRL96, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL96"));
	FlexGridSizer43->Add(tcVch8RetryTimeout, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer41->Add(FlexGridSizer43, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer44 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText177 = new wxStaticText(pVch8, ID_STATICTEXT180, _("Interface Mask"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT180"));
	FlexGridSizer44->Add(StaticText177, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText178 = new wxStaticText(pVch8, ID_STATICTEXT181, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT181"));
	FlexGridSizer44->Add(StaticText178, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8SerialPort = new wxCheckBox(pVch8, ID_CHECKBOX80, _("Serial Port"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX80"));
	cbVch8SerialPort->SetValue(false);
	FlexGridSizer44->Add(cbVch8SerialPort, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText179 = new wxStaticText(pVch8, ID_STATICTEXT182, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT182"));
	FlexGridSizer44->Add(StaticText179, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket0 = new wxCheckBox(pVch8, ID_CHECKBOX81, _("Socket 0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX81"));
	cbVch8Socket0->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket0, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket1 = new wxCheckBox(pVch8, ID_CHECKBOX82, _("Socket 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX82"));
	cbVch8Socket1->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket2 = new wxCheckBox(pVch8, ID_CHECKBOX83, _("Socket 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX83"));
	cbVch8Socket2->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket3 = new wxCheckBox(pVch8, ID_CHECKBOX84, _("Socket 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX84"));
	cbVch8Socket3->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket4 = new wxCheckBox(pVch8, ID_CHECKBOX85, _("Socket 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX85"));
	cbVch8Socket4->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket5 = new wxCheckBox(pVch8, ID_CHECKBOX86, _("Socket 5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX86"));
	cbVch8Socket5->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket6 = new wxCheckBox(pVch8, ID_CHECKBOX87, _("Socket 6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX87"));
	cbVch8Socket6->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbVch8Socket7 = new wxCheckBox(pVch8, ID_CHECKBOX88, _("Socket 7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX88"));
	cbVch8Socket7->SetValue(false);
	FlexGridSizer44->Add(cbVch8Socket7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer41->Add(FlexGridSizer44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer36->Add(FlexGridSizer41, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch8->SetSizer(BoxSizer36);
	BoxSizer36->Fit(pVch8);
	BoxSizer36->SetSizeHints(pVch8);
	nbVch->AddPage(pVch1, _("Virtual Channel 1"), false);
	nbVch->AddPage(pVch2, _("Virtual Channel 2"), false);
	nbVch->AddPage(pVch3, _("Virtual Channel 3"), false);
	nbVch->AddPage(pVch4, _("Virtual Channel 4"), false);
	nbVch->AddPage(pVch5, _("Virtual Channel 5"), false);
	nbVch->AddPage(pVch6, _("Virtual Channel 6"), false);
	nbVch->AddPage(pVch7, _("Virtual Channel 7"), false);
	nbVch->AddPage(pVch8, _("Virtual Channel 8"), false);
	GridSizer3->Add(nbVch, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pVch->SetSizer(GridSizer3);
	GridSizer3->Fit(pVch);
	GridSizer3->SetSizeHints(pVch);
	nbConfig->AddPage(pGeneral, _("General"), false);
	nbConfig->AddPage(pGprs, _("GPRS"), false);
	nbConfig->AddPage(pServer, _("Server"), false);
	nbConfig->AddPage(pVip, _("VIP"), false);
	nbConfig->AddPage(pScripts, _("Scripts"), false);
	nbConfig->AddPage(pSerial, _("Serial Port"), false);
	nbConfig->AddPage(pEthernet, _("Ethernet"), false);
	nbConfig->AddPage(pVch, _("Virtual Channels"), false);
	BoxSizer3->Add(nbConfig, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(BoxSizer3);
	BoxSizer3->Fit(Panel2);
	BoxSizer3->SetSizeHints(Panel2);
	Notebook1->AddPage(Panel1, _("console"), false);
	Notebook1->AddPage(Panel2, _("configuration"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tcCommand = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(474,27), wxTE_PROCESS_ENTER|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer1->Add(tcCommand, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(BoxSizer1);
	fdUpload = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.tlv"), wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&frmConsole::OntcNodeTextEnter);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmConsole::OnbUploadClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmConsole::OnbRefreshConfigClick);
	Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&frmConsole::OnNotebook1PageChanged);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&frmConsole::OntcCommandTextEnter);
	Connect(wxEVT_PAINT,(wxObjectEventFunction)&frmConsole::OnPaint);
	Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&frmConsole::OnKeyDown);
	//*)


  lbScript0->SetName("lbScript0");
  lbScript1->SetName("lbScript1");
  lbScript2->SetName("lbScript2");
  lbScript3->SetName("lbScript3");

  tcEth0Mac->SetName("tcEth0Mac");
  tcEth0Ip->SetName("tcEth0Ip");
  tcEth0Mask->SetName("tcEth0Mask");
  tcEth0Gateway->SetName("tcEth0Gateway");

  tcEth1Mac->SetName("tcEth1Mac");
  tcEth1Ip->SetName("tcEth1Ip");
  tcEth1Mask->SetName("tcEth1Mask");
  tcEth1Gateway->SetName("tcEth1Gateway");

  chSocket0Type->SetName("chSocket0Type");
  tcSocket0DestIp->SetName("tcSocket0DestIp");
  tcSocket0DestPort->SetName("tcSocket0DestPort");
  tcSocket0LocalPort->SetName("tcSocket0LocalPort");
  cbSocket0Ndc->SetName("cbSocket0Ndc");

  chSocket1Type->SetName("chSocket1Type");
  tcSocket1DestIp->SetName("tcSocket1DestIp");
  tcSocket1DestPort->SetName("tcSocket1DestPort");
  tcSocket1LocalPort->SetName("tcSocket1LocalPort");
  cbSocket1Ndc->SetName("cbSocket1Ndc");

  chSocket2Type->SetName("chSocket2Type");
  tcSocket2DestIp->SetName("tcSocket2DestIp");
  tcSocket2DestPort->SetName("tcSocket2DestPort");
  tcSocket2LocalPort->SetName("tcSocket2LocalPort");
  cbSocket2Ndc->SetName("cbSocket2Ndc");

  chSocket3Type->SetName("chSocket3Type");
  tcSocket3DestIp->SetName("tcSocket3DestIp");
  tcSocket3DestPort->SetName("tcSocket3DestPort");
  tcSocket3LocalPort->SetName("tcSocket3LocalPort");
  cbSocket3Ndc->SetName("cbSocket3Ndc");

  chSocket4Type->SetName("chSocket4Type");
  tcSocket4DestIp->SetName("tcSocket4DestIp");
  tcSocket4DestPort->SetName("tcSocket4DestPort");
  tcSocket4LocalPort->SetName("tcSocket4LocalPort");
  cbSocket4Ndc->SetName("cbSocket4Ndc");

  chSocket5Type->SetName("chSocket5Type");
  tcSocket5DestIp->SetName("tcSocket5DestIp");
  tcSocket5DestPort->SetName("tcSocket5DestPort");
  tcSocket5LocalPort->SetName("tcSocket5LocalPort");
  cbSocket5Ndc->SetName("cbSocket5Ndc");

  chSocket6Type->SetName("chSocket6Type");
  tcSocket6DestIp->SetName("tcSocket6DestIp");
  tcSocket6DestPort->SetName("tcSocket6DestPort");
  tcSocket6LocalPort->SetName("tcSocket6LocalPort");
  cbSocket6Ndc->SetName("cbSocket6Ndc");

  chSocket7Type->SetName("chSocket7Type");
  tcSocket7DestIp->SetName("tcSocket7DestIp");
  tcSocket7DestPort->SetName("tcSocket7DestPort");
  tcSocket7LocalPort->SetName("tcSocket7LocalPort");
  cbSocket7Ndc->SetName("cbSocket7Ndc");


  chVch1Switch->SetName("chVch1Switch");
  chVch1WorkMode->SetName("chVch1WorkMode");
  tcVch1DefVipNum->SetName("tcVch1DefVipNum");
  tcVch1ScriptNum->SetName("tcVch1ScriptNum");
  tcVch1Interface->SetName("tcVch1Interface");
  chVch1Channel->SetName("chVch1Channel");
  cbVch1RelayControl->SetName("cbVch1RelayControl");
  tcVch1RelayTime->SetName("tcVch1RelayTime");
  chVch1DelProto->SetName("chVch1DelProto");
  tcVch1WndSize->SetName("tcVch1WndSize");
  tcVch1RetryCnt->SetName("tcVch1RetryCnt");
  tcVch1RetryTimeout->SetName("tcVch1RetryTimeout");
  cbVch1SerialPort->SetName("cbVch1SerialPort");
  cbVch1Socket0->SetName("cbVch1Socket0");
  cbVch1Socket1->SetName("cbVch1Socket1");
  cbVch1Socket2->SetName("cbVch1Socket2");
  cbVch1Socket3->SetName("cbVch1Socket3");
  cbVch1Socket4->SetName("cbVch1Socket4");
  cbVch1Socket5->SetName("cbVch1Socket5");
  cbVch1Socket6->SetName("cbVch1Socket6");
  cbVch1Socket7->SetName("cbVch1Socket7");

  chVch2Switch->SetName("chVch2Switch");
  chVch2WorkMode->SetName("chVch2WorkMode");
  tcVch2DefVipNum->SetName("tcVch2DefVipNum");
  tcVch2ScriptNum->SetName("tcVch2ScriptNum");
  tcVch2Interface->SetName("tcVch2Interface");
  chVch2Channel->SetName("chVch2Channel");
  cbVch2RelayControl->SetName("cbVch2RelayControl");
  tcVch2RelayTime->SetName("tcVch2RelayTime");
  chVch2DelProto->SetName("chVch2DelProto");
  tcVch2WndSize->SetName("tcVch2WndSize");
  tcVch2RetryCnt->SetName("tcVch2RetryCnt");
  tcVch2RetryTimeout->SetName("tcVch2RetryTimeout");
  cbVch2SerialPort->SetName("cbVch2SerialPort");
  cbVch2Socket0->SetName("cbVch2Socket0");
  cbVch2Socket1->SetName("cbVch2Socket1");
  cbVch2Socket2->SetName("cbVch2Socket2");
  cbVch2Socket3->SetName("cbVch2Socket3");
  cbVch2Socket4->SetName("cbVch2Socket4");
  cbVch2Socket5->SetName("cbVch2Socket5");
  cbVch2Socket6->SetName("cbVch2Socket6");
  cbVch2Socket7->SetName("cbVch2Socket7");

  chVch3Switch->SetName("chVch3Switch");
  chVch3WorkMode->SetName("chVch3WorkMode");
  tcVch3DefVipNum->SetName("tcVch3DefVipNum");
  tcVch3ScriptNum->SetName("tcVch3ScriptNum");
  tcVch3Interface->SetName("tcVch3Interface");
  chVch3Channel->SetName("chVch3Channel");
  cbVch3RelayControl->SetName("cbVch3RelayControl");
  tcVch3RelayTime->SetName("tcVch3RelayTime");
  chVch3DelProto->SetName("chVch3DelProto");
  tcVch3WndSize->SetName("tcVch3WndSize");
  tcVch3RetryCnt->SetName("tcVch3RetryCnt");
  tcVch3RetryTimeout->SetName("tcVch3RetryTimeout");
  cbVch3SerialPort->SetName("cbVch3SerialPort");
  cbVch3Socket0->SetName("cbVch3Socket0");
  cbVch3Socket1->SetName("cbVch3Socket1");
  cbVch3Socket2->SetName("cbVch3Socket2");
  cbVch3Socket3->SetName("cbVch3Socket3");
  cbVch3Socket4->SetName("cbVch3Socket4");
  cbVch3Socket5->SetName("cbVch3Socket5");
  cbVch3Socket6->SetName("cbVch3Socket6");
  cbVch3Socket7->SetName("cbVch3Socket7");

  chVch4Switch->SetName("chVch4Switch");
  chVch4WorkMode->SetName("chVch4WorkMode");
  tcVch4DefVipNum->SetName("tcVch4DefVipNum");
  tcVch4ScriptNum->SetName("tcVch4ScriptNum");
  tcVch4Interface->SetName("tcVch4Interface");
  chVch4Channel->SetName("chVch4Channel");
  cbVch4RelayControl->SetName("cbVch4RelayControl");
  tcVch4RelayTime->SetName("tcVch4RelayTime");
  chVch4DelProto->SetName("chVch4DelProto");
  tcVch4WndSize->SetName("tcVch4WndSize");
  tcVch4RetryCnt->SetName("tcVch4RetryCnt");
  tcVch4RetryTimeout->SetName("tcVch4RetryTimeout");
  cbVch4SerialPort->SetName("cbVch4SerialPort");
  cbVch4Socket0->SetName("cbVch4Socket0");
  cbVch4Socket1->SetName("cbVch4Socket1");
  cbVch4Socket2->SetName("cbVch4Socket2");
  cbVch4Socket3->SetName("cbVch4Socket3");
  cbVch4Socket4->SetName("cbVch4Socket4");
  cbVch4Socket5->SetName("cbVch4Socket5");
  cbVch4Socket6->SetName("cbVch4Socket6");
  cbVch4Socket7->SetName("cbVch4Socket7");

  chVch5Switch->SetName("chVch5Switch");
  chVch5WorkMode->SetName("chVch5WorkMode");
  tcVch5DefVipNum->SetName("tcVch5DefVipNum");
  tcVch5ScriptNum->SetName("tcVch5ScriptNum");
  tcVch5Interface->SetName("tcVch5Interface");
  chVch5Channel->SetName("chVch5Channel");
  cbVch5RelayControl->SetName("cbVch5RelayControl");
  tcVch5RelayTime->SetName("tcVch5RelayTime");
  chVch5DelProto->SetName("chVch5DelProto");
  tcVch5WndSize->SetName("tcVch5WndSize");
  tcVch5RetryCnt->SetName("tcVch5RetryCnt");
  tcVch5RetryTimeout->SetName("tcVch5RetryTimeout");
  cbVch5SerialPort->SetName("cbVch5SerialPort");
  cbVch5Socket0->SetName("cbVch5Socket0");
  cbVch5Socket1->SetName("cbVch5Socket1");
  cbVch5Socket2->SetName("cbVch5Socket2");
  cbVch5Socket3->SetName("cbVch5Socket3");
  cbVch5Socket4->SetName("cbVch5Socket4");
  cbVch5Socket5->SetName("cbVch5Socket5");
  cbVch5Socket6->SetName("cbVch5Socket6");
  cbVch5Socket7->SetName("cbVch5Socket7");

  chVch6Switch->SetName("chVch6Switch");
  chVch6WorkMode->SetName("chVch6WorkMode");
  tcVch6DefVipNum->SetName("tcVch6DefVipNum");
  tcVch6ScriptNum->SetName("tcVch6ScriptNum");
  tcVch6Interface->SetName("tcVch6Interface");
  chVch6Channel->SetName("chVch6Channel");
  cbVch6RelayControl->SetName("cbVch6RelayControl");
  tcVch6RelayTime->SetName("tcVch6RelayTime");
  chVch6DelProto->SetName("chVch6DelProto");
  tcVch6WndSize->SetName("tcVch6WndSize");
  tcVch6RetryCnt->SetName("tcVch6RetryCnt");
  tcVch6RetryTimeout->SetName("tcVch6RetryTimeout");
  cbVch6SerialPort->SetName("cbVch6SerialPort");
  cbVch6Socket0->SetName("cbVch6Socket0");
  cbVch6Socket1->SetName("cbVch6Socket1");
  cbVch6Socket2->SetName("cbVch6Socket2");
  cbVch6Socket3->SetName("cbVch6Socket3");
  cbVch6Socket4->SetName("cbVch6Socket4");
  cbVch6Socket5->SetName("cbVch6Socket5");
  cbVch6Socket6->SetName("cbVch6Socket6");
  cbVch6Socket7->SetName("cbVch6Socket7");

  chVch7Switch->SetName("chVch7Switch");
  chVch7WorkMode->SetName("chVch7WorkMode");
  tcVch7DefVipNum->SetName("tcVch7DefVipNum");
  tcVch7ScriptNum->SetName("tcVch7ScriptNum");
  tcVch7Interface->SetName("tcVch7Interface");
  chVch7Channel->SetName("chVch7Channel");
  cbVch7RelayControl->SetName("cbVch7RelayControl");
  tcVch7RelayTime->SetName("tcVch7RelayTime");
  chVch7DelProto->SetName("chVch7DelProto");
  tcVch7WndSize->SetName("tcVch7WndSize");
  tcVch7RetryCnt->SetName("tcVch7RetryCnt");
  tcVch7RetryTimeout->SetName("tcVch7RetryTimeout");
  cbVch7SerialPort->SetName("cbVch7SerialPort");
  cbVch7Socket0->SetName("cbVch7Socket0");
  cbVch7Socket1->SetName("cbVch7Socket1");
  cbVch7Socket2->SetName("cbVch7Socket2");
  cbVch7Socket3->SetName("cbVch7Socket3");
  cbVch7Socket4->SetName("cbVch7Socket4");
  cbVch7Socket5->SetName("cbVch7Socket5");
  cbVch7Socket6->SetName("cbVch7Socket6");
  cbVch7Socket7->SetName("cbVch7Socket7");

  chVch8Switch->SetName("chVch8Switch");
  chVch8WorkMode->SetName("chVch8WorkMode");
  tcVch8DefVipNum->SetName("tcVch8DefVipNum");
  tcVch8ScriptNum->SetName("tcVch8ScriptNum");
  tcVch8Interface->SetName("tcVch8Interface");
  chVch8Channel->SetName("chVch8Channel");
  cbVch8RelayControl->SetName("cbVch8RelayControl");
  tcVch8RelayTime->SetName("tcVch8RelayTime");
  chVch8DelProto->SetName("chVch8DelProto");
  tcVch8WndSize->SetName("tcVch8WndSize");
  tcVch8RetryCnt->SetName("tcVch8RetryCnt");
  tcVch8RetryTimeout->SetName("tcVch8RetryTimeout");
  cbVch8SerialPort->SetName("cbVch8SerialPort");
  cbVch8Socket0->SetName("cbVch8Socket0");
  cbVch8Socket1->SetName("cbVch8Socket1");
  cbVch8Socket2->SetName("cbVch8Socket2");
  cbVch8Socket3->SetName("cbVch8Socket3");
  cbVch8Socket4->SetName("cbVch8Socket4");
  cbVch8Socket5->SetName("cbVch8Socket5");
  cbVch8Socket6->SetName("cbVch8Socket6");
  cbVch8Socket7->SetName("cbVch8Socket7");

  tcNode->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
  //tcCommand->SetValidator(wxCommandValidator());

  DisableControls();
}

frmConsole::~frmConsole()
{
  if (RemoteNode!=0)
    parent->UnregisterNode(RemoteNode);

	//(*Destroy(frmConsole)
	//*)
}

void frmConsole::Output(wxString arText, wxString arColor)
{
  //std::cout << arText << std::endl;

  //ListBox1->Append((wxDateTime::Now()).FormatTime()+wxT(": ")+arText);
  //ListBox1->SetSelection(ListBox1->GetCount()-1);

  int x=0, y=0, xUnit=0, yUnit=0;

  htmlOut->AppendToPage("<PRE><FONT COLOR=\""+arColor+wxT("\">")+
                        ((arText.Contains(*lastCmd))
                        ? (wxDateTime::Now()).FormatTime()+wxT(": ")
                        : wxT(""))
                        + arText+"</FONT></PRE>");

  htmlOut->GetVirtualSize(&x, &y);
  htmlOut->GetScrollPixelsPerUnit(&xUnit, &yUnit);
  htmlOut->Scroll(0, y/yUnit);

//  tcOut->AppendText((wxDateTime::Now()).FormatTime()+wxT(": ")+arText);
  //tcOut->MoveEnd();
//  tcOut->SetSelection(tcOut->GetCount()-1);

}

void frmConsole::OntcNodeTextEnter(wxCommandEvent& event)
{
  (event.GetString().IsEmpty()) ? DisableControls() : EnableControls();

  uint32 tempNode=0;

  if (RemoteNode!=0)
    parent->UnregisterNode(RemoteNode);

  event.GetString().ToLong((long *)&tempNode, 10);

  if (tempNode!=0 && RemoteNode!=tempNode) {
    RemoteNode=tempNode;

    parent->RegisterNode(/*Action(std::tr1::bind(&frmConsole::OnAction, this, _1, _2))*/this, RemoteNode);
    Output(wxT("Node ")+event.GetString()+wxT(" selected"), wxT("#0000FF"));
    SetTitle(event.GetString());
  }
  tcCommand->SetFocus();
}

void frmConsole::OnAction(wxThreadEvent& event)
{
  wxMutexGuiEnter();
  {
    //wxCriticalSectionLocker enter(wxGetApp().critsec);

    if (event.GetInt()==CProto::CONSOLE_INTERFACE_NUMBER)
      Output(event.GetString(), wxT("#A52A2A"));
    else
      ApplyConfig(std::string(event.GetString().mb_str(wxConvUTF8)));
  }
  wxMutexGuiLeave();
}

void frmConsole::OnOut100(wxThreadEvent& event)
{
  Output(event.GetString(), wxT("#A52A2A"));
  //parent->Resume();
}

void frmConsole::OnOut103(wxThreadEvent& event)
{
  if (event.GetInt()!=CProto::ITF_LIST_INTERFACE_NUMBER)
//
//  else
  ApplyConfig(std::string(event.GetString().mb_str(wxConvUTF8)));
}

void frmConsole::OntcCommandTextEnter(wxCommandEvent& event)
{
  MyDefaultBuffer cmd(10, 0);
  cmd[0]=100;
  for (uint32 i=0; i<event.GetString().Length(); i++) {
    cmd.push_back(event.GetString()[i]);
  }
  cmd.push_back('\0');

  if (!event.GetString().IsEmpty()) {
    parent->SendCommand(RemoteNode, CProto::CONSOLE_INTERFACE_NUMBER, cmd);
    if (std::find(lCmdHistory.begin(), lCmdHistory.end(), event.GetString())==lCmdHistory.end()) {
      lCmdHistory.push_back(event.GetString());
      ++lastCmd;
    }
  }

  Output(event.GetString()+wxT(": "), wxT("#008000"));
  tcCommand->Clear();
  tcCommand->SetFocus();
}

void frmConsole::OnPaint(wxPaintEvent& event)
{
  tcNode->SetFocus();
}

void frmConsole::OnKeyDown(wxKeyEvent& event)
{
  if (event.GetKeyCode()==WXK_TAB)
    (wxWindow::FindFocus()!=tcNode) ? tcNode->SetFocus() : tcCommand->SetFocus();
  else if (event.GetKeyCode()==WXK_UP && wxWindow::FindFocus()==tcCommand) {
    getCommandHistory(EDIRECTION::CMD_UP);
  }
  else if (event.GetKeyCode()==WXK_DOWN && wxWindow::FindFocus()==tcCommand) {
    getCommandHistory(EDIRECTION::CMD_DOWN);
  }
}

void frmConsole::OnbRefreshConfigClick(wxCommandEvent& event)
{
  MyDefaultBuffer cmd;
  uint8 b[]={0, 172, 197, 51};
  std::copy(b, b+sizeof(b), std::back_inserter(cmd));
  parent->SendCommand(RemoteNode, CProto::ITF_CONFIG, cmd);
}

void frmConsole::OnNotebook1PageChanged(wxNotebookEvent& event)
{
  if (event.GetSelection()==1) {
    MyDefaultBuffer cmd;
    uint8 b[]={0, 136, 38, 48};
    std::copy(b, b+sizeof(b), std::back_inserter(cmd));
    parent->SendCommand(RemoteNode, CProto::ITF_LIST_INTERFACE_NUMBER, cmd);
  }
}

void frmConsole::getCommandHistory(EDIRECTION arDir)
{
  if (lCmdHistory.empty())
    return;

  if (arDir==EDIRECTION::CMD_UP) {
    tcCommand->SetValue((lastCmd+1!=lCmdHistory.end()) ? *(++lastCmd) : (*lastCmd));
  }
  else if (arDir==EDIRECTION::CMD_DOWN) {
    tcCommand->SetValue((lastCmd!=lCmdHistory.begin()) ? *(--lastCmd) : (*lastCmd));
  }
}

void frmConsole::OnbUploadClick(wxCommandEvent& event)
{
  if (fdUpload->ShowModal()==wxID_OK) {
//    if (!fdUpload->GetFilename().IsEmpty()) {
    std::string sFullPath(fdUpload->GetPath().mb_str(wxConvUTF8));
    std::string sFileName(fdUpload->GetFilename().mb_str(wxConvUTF8));
    parent->SendFile(RemoteNode, CProto::CONSOLE_INTERFACE_NUMBER, sFullPath, sFileName);
//    }
  }
}

void frmConsole::ApplyConfig(std::string arXml)
{
  pugi::xml_document doc;
  std::istringstream ss(arXml);
  //wxMessageBox(arXml);

  pugi::xml_parse_result result=doc.load(ss);
  if (!result) {
    wxMessageBox(result.description());
    return;

  }

/*
  switch (doc.load(ss)) {
    case pugi::status_ok:
      wxMessageBox("No error.");
      break;
    case pugi::status_file_not_found:
      wxMessageBox(wxT("File was not found during load_file()."));
      return;
    case pugi::status_io_error:
      wxMessageBox(wxT("Error reading from file/stream."));
      return;
    case pugi::status_out_of_memory:
      wxMessageBox("Could not allocate memory.");
      return;
    case pugi::status_internal_error:
      wxMessageBox("Internal error occured.");
      return;
    case pugi::status_unrecognized_tag:
      wxMessageBox("Parser could not determine tag type.");
      return;
    case pugi::status_bad_pi:
      wxMessageBox("Parsing error occured while parsing document declaration/processing instruction (<?...?>).");
      return;
    case pugi::status_bad_comment:
      wxMessageBox("Parsing error occured while parsing comment ().");
      return;
    case pugi::status_bad_cdata:
      wxMessageBox("Parsing error occured while parsing CDATA section (<![CDATA[...]]>).");
      return;
    case pugi::status_bad_doctype:
      wxMessageBox("Parsing error occured while parsing document type declaration.");
      return;
    case pugi::status_bad_pcdata:
      wxMessageBox("Parsing error occured while parsing PCDATA section (>...<).");
      return;
    case pugi::status_bad_start_element:
      wxMessageBox("Parsing error occured while parsing start element tag (<name ...>).");
      return;
    case pugi::status_bad_attribute:
      wxMessageBox("Parsing error occured while parsing element attribute.");
      return;
    case pugi::status_bad_end_element:
      wxMessageBox("Parsing error occured while parsing end element tag (</name>).");
      return;
    case pugi::status_end_element_mismatch:
      wxMessageBox("There was a mismatch of start-end tags (closing tag had incorrect name, some tag was not closed or there was an excessive closing tag).");
      return;
  }
*/
  pugi::xml_node configuration=doc.child("configuration");

  pugi::xml_node general=configuration.child("general");
  pugi::xml_node gprs=configuration.child("gprs");
  pugi::xml_node server=configuration.child("server");
  pugi::xml_node vip=configuration.child("vip");
  pugi::xml_node scripts=configuration.child("scripts");
  pugi::xml_node serialport=configuration.child("serialport");
  pugi::xml_node ethernet=configuration.child("ethernet");
  pugi::xml_node sockets=ethernet.child("sockets");
  pugi::xml_node virtualchannels=configuration.child("virtualchannels");

//  std::cout << general.child("ip_conn_timeout").first_child().value() << std::endl;

  (!general.child("ip_conn_timeout").empty())
  ? tcIpConnTimeout->SetValue(general.child("ip_conn_timeout").first_child().value())
  : tcIpConnTimeout->SetValue("");

  (!general.child("gprs_conn_timeout").empty())
  ? tcGprsConnTimeout->SetValue(general.child("gprs_conn_timeout").first_child().value())
  : tcGprsConnTimeout->SetValue("");

  (!general.child("max_ip_pwrup_delay").empty())
  ? tcMaxIpPwrDelay->SetValue(general.child("max_ip_pwrup_delay").first_child().value())
  : tcMaxIpPwrDelay->SetValue("");

  (!general.child("csq_min_value").empty())
  ? tcCSQMinVal->SetValue(general.child("csq_min_value").first_child().value())
  : tcCSQMinVal->SetValue("");

  (!general.child("ip_packet_max_len").empty())
  ? tcIpPacketMaxLen->SetValue(general.child("ip_packet_max_len").first_child().value())
  : tcIpPacketMaxLen->SetValue("");

  (!general.child("trace_answer").empty())
  ? tcTraceAnswer->SetValue(general.child("trace_answer").first_child().value())
  : tcTraceAnswer->SetValue("");

  (!general.child("debug").empty())
  ? chDebug->SetSelection(atoi(general.child("trace_answer").first_child().value()))
  : chDebug->SetSelection(0);

  (!general.child("channel_priority").empty())
  ? chDebug->SetSelection(atoi(general.child("channel_priority").first_child().value()))
  : chDebug->SetSelection(0);


  if (!serialport.child("baudrate").empty()) {
    uint32 i=atoi(serialport.child("baudrate").first_child().value());
    if (mBaud.find(i)!=mBaud.end()) {
      chBaud->SetSelection(mBaud[i]);
    }
    else
      chBaud->SetSelection(-1);
  }
  else
   chDebug->SetSelection(-1);

  (!serialport.child("flow_control").empty())
  ? chFlowCtrl->SetSelection(atoi(serialport.child("flow_control").first_child().value()))
  : chFlowCtrl->SetSelection(0);

  if (!gprs.empty()) {
    uint32 r=0;
    pugi::xml_node row=gprs.first_child();
    while (!row.empty()) {
      if (!row.child("operator_id").empty()) {
        gGprs->SetCellValue(r, 0, row.child("operator_id").first_child().value());
      }

      if (!row.child("username").empty()) {
        gGprs->SetCellValue(r, 1, row.child("username").first_child().value());
      }

      if (!row.child("password").empty()) {
        gGprs->SetCellValue(r, 2, row.child("password").first_child().value());
      }

      if (!row.child("apn").empty()) {
        gGprs->SetCellValue(r, 3, row.child("apn").first_child().value());
      }

      if (!row.child("auto_disconnect").empty()) {
        gGprs->SetCellValue(r, 4, row.child("auto_disconnect").first_child().value());
      }

      row=row.next_sibling();
      ++r;
    }
  }

  if (!server.empty()) {
    uint32 r=0;
    pugi::xml_node row=server.first_child();
    while (!row.empty()) {
      if (!row.child("server_node").empty()) {
        gServer->SetCellValue(r, 0, row.child("server_node").first_child().value());
      }

      if (!row.child("server_ip").empty()) {
        gServer->SetCellValue(r, 1, row.child("server_ip").first_child().value());
      }

      if (!row.child("server_port").empty()) {
        gServer->SetCellValue(r, 2, row.child("server_port").first_child().value());
      }

      if (!row.child("ka_send").empty()) {
        gServer->SetCellValue(r, 3, row.child("ka_send").first_child().value());
      }

      if (!row.child("ka_recv").empty()) {
        gServer->SetCellValue(r, 4, row.child("ka_recv").first_child().value());
      }

      row=row.next_sibling();
      ++r;
    }
  }

  if (!vip.empty()) {
    uint32 r=0;
    pugi::xml_node row=vip.first_child();
    while (!row.empty()) {
      if (!row.child("server_node").empty()) {
        gVip->SetCellValue(r, 0, row.child("server_node").first_child().value());
      }

      if (!row.child("server_itf").empty()) {
        gVip->SetCellValue(r, 1, row.child("server_itf").first_child().value());
      }

      if (!row.child("flags").empty()) {
        gVip->SetCellValue(r, 2, row.child("flags").first_child().value());
      }

      if (!row.child("ka_send").empty()) {
        gVip->SetCellValue(r, 3, row.child("ka_send").first_child().value());
      }

      if (!row.child("ka_recv").empty()) {
        gVip->SetCellValue(r, 4, row.child("ka_recv").first_child().value());
      }

      if (!row.child("idle_time").empty()) {
        gVip->SetCellValue(r, 5, row.child("idle_time").first_child().value());
      }

      if (!row.child("connect_timeout").empty()) {
        gVip->SetCellValue(r, 6, row.child("connect_timeout").first_child().value());
      }

      if (!row.child("connection_time").empty()) {
        gVip->SetCellValue(r, 7, row.child("connection_time").first_child().value());
      }

      if (!row.child("reserve_host").empty()) {
        gVip->SetCellValue(r, 8, row.child("reserve_host").first_child().value());
      }

      row=row.next_sibling();
      ++r;
    }
  }

  if (!scripts.empty()) {
    pugi::xml_node row=scripts.first_child();
    wxListBox *lb=NULL;

    while (!row.empty()) {
      if (!row.child("id").empty()) {
        lb=(wxListBox *)pScripts->FindWindowByName("lbScript"+wxString(row.child("id").first_child().value()));
      }

      if (!row.child("value").empty()) {
        if (lb!=NULL) {
          lb->Append(row.child("value").first_child().value());
        }
      }

      row=row.next_sibling();
    }
  }

  if (!ethernet.empty()) {
    pugi::xml_node row=ethernet.first_child();
    wxTextCtrl *lb=NULL;

    while (!row.empty()) {
      if (!row.child("mac").empty()) {
        if ((lb=(wxTextCtrl *)pEthernet->FindWindowByName(
              "tcEth"+wxString(row.child("id").first_child().value())+"Mac"))!=NULL) {
          lb->SetValue(row.child("mac").first_child().value());
        }
      }

      if (!row.child("ip").empty()) {
        if ((lb=(wxTextCtrl *)pEthernet->FindWindowByName(
              "tcEth"+wxString(row.child("id").first_child().value())+"Ip"))!=NULL) {
          lb->SetValue(row.child("ip").first_child().value());
        }
      }

      if (!row.child("mask").empty()) {
        if ((lb=(wxTextCtrl *)pEthernet->FindWindowByName(
              "tcEth"+wxString(row.child("id").first_child().value())+"Mask"))!=NULL) {
          lb->SetValue(row.child("mask").first_child().value());
        }
      }

      if (!row.child("gateway").empty()) {
        if ((lb=(wxTextCtrl *)pEthernet->FindWindowByName(
              "tcEth"+wxString(row.child("id").first_child().value())+"Gateway"))!=NULL) {
          lb->SetValue(row.child("gateway").first_child().value());
        }
      }

      row=row.next_sibling();
    }
  }

  if (!sockets.empty()) {
    pugi::xml_node row=sockets.first_child();
    wxWindow *lb=NULL;

    while (!row.empty()) {
      if (!row.child("type").empty()) {
        if ((lb=pEthernet->FindWindowByName(
              "chSocket"+wxString(row.child("id").first_child().value())+"Type"))!=NULL) {
          ((wxChoice *)lb)->SetSelection(atoi(row.child("type").first_child().value()));
        }
      }

      if (!row.child("dest_ip").empty()) {
        if ((lb=pEthernet->FindWindowByName(
              "tcSocket"+wxString(row.child("id").first_child().value())+"DestIp"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("dest_ip").first_child().value());
        }
      }

      if (!row.child("dest_port").empty()) {
        if ((lb=pEthernet->FindWindowByName(
              "tcSocket"+wxString(row.child("id").first_child().value())+"DestPort"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("dest_port").first_child().value());
        }
      }

      if (!row.child("local_port").empty()) {
        if ((lb=pEthernet->FindWindowByName(
              "tcSocket"+wxString(row.child("id").first_child().value())+"LocalPort"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("local_port").first_child().value());
        }
      }

      if (!row.child("ndc").empty()) {
        if ((lb=pEthernet->FindWindowByName(
              "cbSocket"+wxString(row.child("id").first_child().value())+"Ndc"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("ndc").first_child().value()));
        }
      }

      row=row.next_sibling();
    }
  }



  if (!virtualchannels.empty()) {
    pugi::xml_node row=virtualchannels.first_child();
    wxWindow *lb=NULL;

    while (!row.empty()) {
      if (!row.child("mode").empty()) {
        if ((lb=pVch->FindWindowByName(
              "chVch"+wxString(row.child("id").first_child().value())+"Switch"))!=NULL) {
          ((wxChoice *)lb)->SetSelection(atoi(row.child("mode").first_child().value()));
        }
      }

      if (!row.child("work_mode").empty()) {
        if ((lb=pVch->FindWindowByName(
              "chVch"+wxString(row.child("id").first_child().value())+"WorkMode"))!=NULL) {
          ((wxChoice *)lb)->SetSelection(atoi(row.child("wok_mode").first_child().value()));
        }
      }

      if (!row.child("vip_number").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"DefVipNum"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("vip_number").first_child().value());
        }
      }

      if (!row.child("script_number").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"ScriptNum"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("script_number").first_child().value());
        }
      }

      if (!row.child("server_interface").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"Interface"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("server_interface").first_child().value());
        }
      }

      if (!row.child("server_pch").empty()) {
        if ((lb=pVch->FindWindowByName(
              "chVch"+wxString(row.child("id").first_child().value())+"Channel"))!=NULL) {
          ((wxChoice *)lb)->SetSelection(atoi(row.child("server_pch").first_child().value()));
        }
      }

      if (!row.child("relay_control").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"RelayControl"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("relay_control").first_child().value()));
        }
      }

      if (!row.child("relay_timeout").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"RelayTime"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("relay_timeout").first_child().value());
        }
      }

      if (!row.child("dp_mode").empty()) {
        if ((lb=pVch->FindWindowByName(
              "chVch"+wxString(row.child("id").first_child().value())+"DelProto"))!=NULL) {
          ((wxChoice *)lb)->SetSelection(atoi(row.child("dp_mode").first_child().value()));
        }
      }

      if (!row.child("dp_window_size").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"WndSize"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("dp_window_size").first_child().value());
        }
      }

      if (!row.child("dp_retry_count").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"RetryCnt"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("dp_retry_count").first_child().value());
        }
      }

      if (!row.child("dp_retry_timeout").empty()) {
        if ((lb=pVch->FindWindowByName(
              "tcVch"+wxString(row.child("id").first_child().value())+"RetryTimeout"))!=NULL) {
          ((wxTextCtrl *)lb)->SetValue(row.child("dp_retry_timeout").first_child().value());
        }
      }

      if (!row.child("itf_mask_serial_port").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"SerialPort"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_serial_port").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_0").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket0"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_0").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_1").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket1"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_1").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_2").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket2"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_2").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_3").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket3"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_3").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_4").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket4"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_4").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_5").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket5"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_5").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_6").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket6"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_6").first_child().value()));
        }
      }

      if (!row.child("itf_mask_sock_7").empty()) {
        if ((lb=pVch->FindWindowByName(
              "cbVch"+wxString(row.child("id").first_child().value())+"Socket7"))!=NULL) {
          ((wxCheckBox *)lb)->SetValue(atoi(row.child("itf_mask_sock_7").first_child().value()));
        }
      }

      row=row.next_sibling();
    }
  }


}

void frmConsole::EnableControls()
{
  Notebook1->Enable(true);
  tcCommand->Enable(true);
}

void frmConsole::DisableControls()
{
  Notebook1->Enable(false);
  tcCommand->Enable(false);
}
