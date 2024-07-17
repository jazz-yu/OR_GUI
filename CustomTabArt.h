// CustomTabArt.h
#pragma once

#include <wx/aui/auibook.h>

class CustomTabArt : public wxAuiDefaultTabArt {
public:
    CustomTabArt();
    virtual ~CustomTabArt();

    virtual void DrawBackground(wxDC& dc, wxWindow* wnd, const wxRect& rect);
    virtual void DrawTab(wxDC& dc, wxWindow* wnd, const wxAuiNotebookPage& page, const wxRect& rect, int close_button_state, wxRect* out_tab_rect, wxRect* out_button_rect, int* x_extent);
};
