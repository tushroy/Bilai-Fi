/***************************************************************
 * Name:      Bilai_FiMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tushar Roy (xxcrack@gmail.com)
 * Created:   2012-08-14
 * Copyright: Tushar Roy (http://www.tushroy.com/)
 * License:
 **************************************************************/

#ifndef BILAI_FIMAIN_H
#define BILAI_FIMAIN_H

//(*Headers(Bilai_FiFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class Bilai_FiFrame: public wxFrame
{
    public:

        Bilai_FiFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Bilai_FiFrame();

    private:

        //(*Handlers(Bilai_FiFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnStartClick(wxCommandEvent& event);
        void OnbtnExitClick(wxCommandEvent& event);
        void OnbtnAboutClick(wxCommandEvent& event);
        void OnbtnStopClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Bilai_FiFrame)
        static const long ID_STATICBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_SSID;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_TEXTCTRL1;
        static const long ID_PANEL2;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(Bilai_FiFrame)
        wxButton* btnStop;
        wxTextCtrl* txtPass;
        wxButton* btnAbout;
        wxStaticText* StaticText2;
        wxButton* btnStart;
        wxTextCtrl* txtSSID;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticBox* StaticBox1;
        wxButton* btnExit;
        wxTextCtrl* TextCtrl1;
        wxPanel* Panel2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BILAI_FIMAIN_H
