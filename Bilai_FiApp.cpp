/***************************************************************
 * Name:      Bilai_FiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Tushar Roy (xxcrack@gmail.com)
 * Created:   2012-08-14
 * Copyright: Tushar Roy (http://www.tushroy.com/)
 * License:
 **************************************************************/

#include "Bilai_FiApp.h"

//(*AppHeaders
#include "Bilai_FiMain.h"
#include <wx/image.h>
//*)

#include "runas.cpp"

IMPLEMENT_APP(Bilai_FiApp);

bool Bilai_FiApp::OnInit()
{
    if(!IsAppRunningAsAdminMode())
    {
        runAdmin();
    }
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Bilai_FiFrame* Frame = new Bilai_FiFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
