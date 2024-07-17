#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/imagpng.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    // Create the main frame
    MainFrame* mainFrame = new MainFrame("Operation Research toolkit");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();

    // Set application icon using resource identifier
     wxIcon icon;
    icon.CopyFromBitmap(wxBitmap(wxICON(ICON.png))); // Load icon from resource IDB_PNG1
     mainFrame->SetIcon(icon);

    // Show the main frame
    mainFrame->Show();

    return true;
}
