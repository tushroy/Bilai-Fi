/***************************************************************
 * Name:      Bilai_FiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Tushar Roy (xxcrack@gmail.com)
 * Created:   2012-08-14
 * Copyright: Tushar Roy (http://www.tushroy.com/)
 * License:
 **************************************************************/

#include "Bilai_FiMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Bilai_FiFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include<windows.h>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Bilai_FiFrame)
const long Bilai_FiFrame::ID_STATICBOX1 = wxNewId();
const long Bilai_FiFrame::ID_STATICTEXT1 = wxNewId();
const long Bilai_FiFrame::ID_SSID = wxNewId();
const long Bilai_FiFrame::ID_STATICTEXT2 = wxNewId();
const long Bilai_FiFrame::ID_TEXTCTRL2 = wxNewId();
const long Bilai_FiFrame::ID_BUTTON1 = wxNewId();
const long Bilai_FiFrame::ID_BUTTON2 = wxNewId();
const long Bilai_FiFrame::ID_BUTTON3 = wxNewId();
const long Bilai_FiFrame::ID_BUTTON4 = wxNewId();
const long Bilai_FiFrame::ID_TEXTCTRL1 = wxNewId();
const long Bilai_FiFrame::ID_PANEL2 = wxNewId();
const long Bilai_FiFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Bilai_FiFrame,wxFrame)
    //(*EventTable(Bilai_FiFrame)
    //*)
END_EVENT_TABLE()

Bilai_FiFrame::Bilai_FiFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Bilai_FiFrame)
    Create(parent, wxID_ANY, _("Bilai-Fi Connect"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(388,236));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(120,208), wxSize(384,236), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("Setup"), wxPoint(16,16), wxSize(224,168), 0, _T("ID_STATICBOX1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("SSID:"), wxPoint(64,56), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    txtSSID = new wxTextCtrl(Panel1, ID_SSID, _("Bilai-Fi"), wxPoint(112,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_SSID"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Password:"), wxPoint(40,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    txtPass = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("12345678"), wxPoint(112,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    btnStart = new wxButton(Panel1, ID_BUTTON1, _("&Start"), wxPoint(40,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnStop = new wxButton(Panel1, ID_BUTTON2, _("St&op"), wxPoint(136,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnExit = new wxButton(Panel1, ID_BUTTON3, _("E&xit"), wxPoint(272,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    btnAbout = new wxButton(Panel1, ID_BUTTON4, _("&About"), wxPoint(272,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(248,96), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, _("Use atleast 6 characters in SSID field and \n\nUse atleast 8 characters in Password field. \n\nDo not left the fields blank."), wxPoint(0,0), wxSize(128,128), wxTE_NO_VSCROLL|wxTE_MULTILINE|wxNO_BORDER|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->Disable();
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bilai_FiFrame::OnbtnStartClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bilai_FiFrame::OnbtnStopClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bilai_FiFrame::OnbtnExitClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bilai_FiFrame::OnbtnAboutClick);
    //*)

        FILE *fp=fopen("statedata.dat","r");
    if(!fp)
    {
        fp= fopen("statedata.dat","w");
        fprintf(fp,"%d",0);
        btnStop->Enable(false);
    }
    int data;
    fscanf(fp,"%d",&data);
    if(data==1)
    {
       //WinExec("notepad.exe",SW_SHOW);
       btnStart->Enable(false);
    }
    else
    {
        btnStop->Enable(false);
    }
    fclose(fp);

}

Bilai_FiFrame::~Bilai_FiFrame()
{
    //(*Destroy(Bilai_FiFrame)
    //*)
}

void Bilai_FiFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Bilai_FiFrame::OnbtnStartClick(wxCommandEvent& event)
{
    WinExec("netsh wlan set hostednetwork mode=allow ssid=\""+txtSSID->GetValue()+"\" key=\""+txtPass->GetValue()+"\" keyUsage=persistent",SW_HIDE);
    WinExec("netsh wlan start hostednetwork",SW_HIDE);
    btnStart->Enable(false);
    btnStop->Enable(true);
    FILE *fp= fopen("statedata.dat","w");
    fprintf(fp,"%d",1);
    fclose(fp);
}
void Bilai_FiFrame::OnbtnStopClick(wxCommandEvent& event)
{
    WinExec("netsh wlan stop hostednetwork",SW_HIDE);
    btnStart->Enable(true);
    btnStop->Enable(false);
    FILE *fp= fopen("statedata.dat","w");
    fprintf(fp,"%d",0);
    fclose(fp);
}

void Bilai_FiFrame::OnbtnExitClick(wxCommandEvent& event)
{
    exit(0);
}

void Bilai_FiFrame::OnbtnAboutClick(wxCommandEvent& event)
{
    wxMessageBox("Developer: Tushar Roy \nIdea: Abdullah Al Farhan", _("About Bilai-Fi Connect..."));
}


