// CustomTabArt.cpp
#include "CustomTabArt.h"
#include <wx/dcclient.h>

CustomTabArt::CustomTabArt() {
    // Constructor implementation if needed
}

CustomTabArt::~CustomTabArt() {
    // Destructor implementation if needed
}

void CustomTabArt::DrawBackground(wxDC& dc, wxWindow* wnd, const wxRect& rect) {
    // Custom background drawing code here
    wxColour backgroundColor = wxColour(255, 155, 0); // Example: Yellow color
    dc.SetPen(wxPen(backgroundColor));
    dc.SetBrush(wxBrush(backgroundColor));
    dc.DrawRectangle(rect);
}

void CustomTabArt::DrawTab(wxDC& dc, wxWindow* wnd, const wxAuiNotebookPage& page, const wxRect& rect, int close_button_state, wxRect* out_tab_rect, wxRect* out_button_rect, int* x_extent) {
    // Custom tab drawing code here
    wxColour tabColor = wxColour(255, 255, 0); // Example: Red color
    dc.SetPen(wxPen(tabColor));
    dc.SetBrush(wxBrush(tabColor));
    dc.DrawRectangle(rect);

    // Example: Draw tab text
    wxString tabText = page.caption;
    dc.DrawText(tabText, rect.GetX() + 5, rect.GetY() + 5);

    // Example: Calculate tab and button rectangles
    *out_tab_rect = rect;
    *out_button_rect = wxRect(); // No close button in this example
    *x_extent = 100; // Example extent width
}
