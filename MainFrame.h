#pragma once

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/aui/auibook.h>
#include <vector>


class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    wxAuiNotebook* m_notebook;
    wxSpinCtrl* m_spinCtrl;
    wxStaticText* m_resultText;

    wxStaticText* single_x1;
    wxChoice* single_x1ConChoice;
    wxTextCtrl* single_x1ConValue;

    wxStaticText* single_x2;
    wxChoice* single_x2ConChoice;
    wxTextCtrl* single_x2ConValue;

    wxStaticText* single_x3;
    wxChoice* single_x3ConChoice;
    wxTextCtrl* single_x3ConValue;

    wxStaticText* single_x4;
    wxChoice* single_x4ConChoice;
    wxTextCtrl* single_x4ConValue;

    // Objective function controls
    wxRadioBox* m_radioBoxObjective;

    // 4 parameters ctrl
    wxTextCtrl* x1para_ctrl;
    wxTextCtrl* x2para_ctrl;
    wxTextCtrl* x3para_ctrl;
    wxTextCtrl* x4para_ctrl;

    // Text
    wxStaticText* debug_var;

    // Spin ctrl
    wxSpinCtrl* con_spinctrl;

    // Button
    wxButton* gener_con_btn;

    // Sizer
    wxBoxSizer* sizerConstraints;

    // Scroll bar 4 panel 2
    wxScrolledWindow* panel;
    wxScrolledWindow* panel2;

    //constant numbers
    bool have_you_generate = false;
    std::vector<float> obj_array;
    std::vector<float> constrain_array;

    // Event handlers
    void OnButtonClicked(wxCommandEvent& event); // This is for calculation
    void Generate_con(wxCommandEvent& event); // This is for generating constraints
    void FetchAndDisplayConstraints(); // Get all the values and store them
    void InitializeComponents();
    void CreateSimplexTab();
    void CreateNLP_Tab();
    void SetupMainSizer();
    wxDECLARE_EVENT_TABLE();
};
