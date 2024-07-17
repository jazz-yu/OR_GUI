#include "MainFrame.h"
#include "CustomTabArt.h" // Include CustomTabArt header


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {
    InitializeComponents();
    SetupMainSizer();
}

void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    FetchAndDisplayConstraints();

}

void MainFrame::Generate_con(wxCommandEvent& event) {
    sizerConstraints->Clear(true); // Clear previous constraints
    have_you_generate = true;

    int numConstraints = con_spinctrl->GetValue();
    wxString op_choices[] = { "+", "-", "*" };
    wxString con_choices[] = { "<", ">", "<=", ">=", "=" };

    // Add single constraints (x1, x2, x3, x4)
    wxBoxSizer* singleConstraintRow = new wxBoxSizer(wxHORIZONTAL);

    single_x1 = new wxStaticText(panel2, wxID_ANY, "x1", wxDefaultPosition, wxSize(30, -1));
    single_x1ConChoice = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(con_choices) / sizeof(con_choices[0]), con_choices);
    single_x1ConValue = new wxTextCtrl(panel2, wxID_ANY, "0", wxDefaultPosition, wxSize(50, -1));

    single_x2 = new wxStaticText(panel2, wxID_ANY, ", x2", wxDefaultPosition, wxSize(30, -1));
    single_x2ConChoice = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(con_choices) / sizeof(con_choices[0]), con_choices);
    single_x2ConValue = new wxTextCtrl(panel2, wxID_ANY, "0", wxDefaultPosition, wxSize(50, -1));

    single_x3 = new wxStaticText(panel2, wxID_ANY, ", x3", wxDefaultPosition, wxSize(30, -1));
    single_x3ConChoice = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(con_choices) / sizeof(con_choices[0]), con_choices);
    single_x3ConValue = new wxTextCtrl(panel2, wxID_ANY, "0", wxDefaultPosition, wxSize(50, -1));

    single_x4 = new wxStaticText(panel2, wxID_ANY, ", x4", wxDefaultPosition, wxSize(30, -1));
    single_x4ConChoice = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(con_choices) / sizeof(con_choices[0]), con_choices);
    single_x4ConValue = new wxTextCtrl(panel2, wxID_ANY, "0", wxDefaultPosition, wxSize(50, -1));

    // Add controls to the sizer
    singleConstraintRow->Add(single_x1, 0, wxALL, 5);
    singleConstraintRow->Add(single_x1ConChoice, 0, wxALL, 5);
    singleConstraintRow->Add(single_x1ConValue, 0, wxALL, 5);

    singleConstraintRow->Add(single_x2, 0, wxALL, 5);
    singleConstraintRow->Add(single_x2ConChoice, 0, wxALL, 5);
    singleConstraintRow->Add(single_x2ConValue, 0, wxALL, 5);

    singleConstraintRow->Add(single_x3, 0, wxALL, 5);
    singleConstraintRow->Add(single_x3ConChoice, 0, wxALL, 5);
    singleConstraintRow->Add(single_x3ConValue, 0, wxALL, 5);

    singleConstraintRow->Add(single_x4, 0, wxALL, 5);
    singleConstraintRow->Add(single_x4ConChoice, 0, wxALL, 5);
    singleConstraintRow->Add(single_x4ConValue, 0, wxALL, 5);

    sizerConstraints->Add(singleConstraintRow, 0, wxALL, 5);

    // Add the rest of the constraints
    for (int i = 1; i <= numConstraints; ++i) {
        wxBoxSizer* constraintRow = new wxBoxSizer(wxHORIZONTAL);

        wxTextCtrl* constraint_x1 = new wxTextCtrl(panel2, wxID_ANY, "", wxDefaultPosition, wxSize(30, -1));
        wxStaticText* constraint_x1Text = new wxStaticText(panel2, wxID_ANY, "x1");
        wxChoice* opChoice_con_1 = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(op_choices) / sizeof(op_choices[0]), op_choices);

        wxTextCtrl* constraint_x2 = new wxTextCtrl(panel2, wxID_ANY, "", wxDefaultPosition, wxSize(30, -1));
        wxStaticText* constraint_x2Text = new wxStaticText(panel2, wxID_ANY, "x2");
        wxChoice* opChoice_con_2 = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(op_choices) / sizeof(op_choices[0]), op_choices);

        wxTextCtrl* constraint_x3 = new wxTextCtrl(panel2, wxID_ANY, "", wxDefaultPosition, wxSize(30, -1));
        wxStaticText* constraint_x3Text = new wxStaticText(panel2, wxID_ANY, "x3");
        wxChoice* opChoice_con_3 = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(op_choices) / sizeof(op_choices[0]), op_choices);

        wxTextCtrl* constraint_x4 = new wxTextCtrl(panel2, wxID_ANY, "", wxDefaultPosition, wxSize(30, -1));
        wxStaticText* constraint_x4Text = new wxStaticText(panel2, wxID_ANY, "x4");

        wxChoice* conChoice = new wxChoice(panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(con_choices) / sizeof(con_choices[0]), con_choices);
        wxTextCtrl* con_value = new wxTextCtrl(panel2, wxID_ANY, "", wxDefaultPosition, wxSize(50, -1));

        // Set names for later retrieval
        constraint_x1->SetName(wxString::Format("constraint_x1_%d", i));
        opChoice_con_1->SetName(wxString::Format("opChoice_con_1_%d", i));
        constraint_x2->SetName(wxString::Format("constraint_x2_%d", i));
        opChoice_con_2->SetName(wxString::Format("opChoice_con_2_%d", i));
        constraint_x3->SetName(wxString::Format("constraint_x3_%d", i));
        opChoice_con_3->SetName(wxString::Format("opChoice_con_3_%d", i));
        constraint_x4->SetName(wxString::Format("constraint_x4_%d", i));
        conChoice->SetName(wxString::Format("conChoice_%d", i));
        con_value->SetName(wxString::Format("con_value_%d", i));

        // Add controls to the sizer
        constraintRow->Add(constraint_x1, 0, wxALL, 5);
        constraintRow->Add(constraint_x1Text, 0, wxALL, 5);
        constraintRow->Add(opChoice_con_1, 0, wxALL, 5);
        constraintRow->Add(constraint_x2, 0, wxALL, 5);
        constraintRow->Add(constraint_x2Text, 0, wxALL, 5);
        constraintRow->Add(opChoice_con_2, 0, wxALL, 5);
        constraintRow->Add(constraint_x3, 0, wxALL, 5);
        constraintRow->Add(constraint_x3Text, 0, wxALL, 5);
        constraintRow->Add(opChoice_con_3, 0, wxALL, 5);
        constraintRow->Add(constraint_x4, 0, wxALL, 5);
        constraintRow->Add(constraint_x4Text, 0, wxALL, 5);
        constraintRow->Add(conChoice, 0, wxALL, 5);
        constraintRow->Add(con_value, 0, wxALL, 5);

        sizerConstraints->Add(constraintRow, 0, wxALL, 5);
    }

    sizerConstraints->Layout();
    panel2->FitInside();
    panel2->SetScrollRate(5, 5);
    panel2->Layout();
}

void SimplexMethod(bool isMaximize, double x1_coeff, double x2_coeff, double x3_coeff, double x4_coeff, const std::vector<std::vector<double>>& constraints) {

}

void MainFrame::FetchAndDisplayConstraints() {
    if (have_you_generate == false) {
        m_resultText->SetLabel("Please generate constrains!!");
        return;
    } //don't enter when no constrains number input

    wxString constraints;
    constraints += single_x1->GetLabel() + " " + single_x1ConChoice->GetStringSelection() + " " + single_x1ConValue->GetValue();
    constraints += single_x2->GetLabel() + " " + single_x2ConChoice->GetStringSelection() + " " + single_x2ConValue->GetValue();
    constraints += single_x3->GetLabel() + " " + single_x3ConChoice->GetStringSelection() + " " + single_x3ConValue->GetValue();
    constraints += single_x4->GetLabel() + " " + single_x4ConChoice->GetStringSelection() + " " + single_x4ConValue->GetValue();



    wxArrayString constraints_array;
    constraints_array.Add(constraints);

    // Display constraints for now
    wxString constraintsText;
    for (size_t i = 0; i < constraints_array.GetCount(); ++i) {
        constraintsText += constraints_array[i] + " ";
    }

    m_resultText->SetLabel(constraintsText + " ");
    // m_resultText->SetLabel( "This function is under developing!");
}

void MainFrame::InitializeComponents() {
    panel = new wxScrolledWindow(this);

    // Create a notebook with custom tab art
    m_notebook = new wxAuiNotebook(panel, wxID_ANY, wxPoint(0, 0), wxSize(600, 400));
    m_notebook->SetArtProvider(new CustomTabArt()); // Set custom tab art provider

    CreateSimplexTab();
    CreateNLP_Tab();
}

void MainFrame::CreateSimplexTab() {
    wxPanel* page1 = new wxPanel(m_notebook);
    wxStaticBox* box1 = new wxStaticBox(page1, wxID_ANY, "Objective");
    wxStaticBoxSizer* boxSizer1 = new wxStaticBoxSizer(box1, wxVERTICAL);

    wxBoxSizer* sizerObjective = new wxBoxSizer(wxHORIZONTAL);
    wxString choices[] = { "Maximize", "Minimize" };
    m_radioBoxObjective = new wxRadioBox(page1, wxID_ANY, "Objective:", wxDefaultPosition, wxDefaultSize, sizeof(choices) / sizeof(choices[0]), choices, 1, wxRA_SPECIFY_COLS);
    wxStaticText* Z = new wxStaticText(page1, wxID_ANY, "Z =", wxPoint(120, 10));

    wxString op_choices[] = { "+", "-", "*" };
    wxString con_choices[] = { "<", ">", "<=", ">=", "=" };

    x1para_ctrl = new wxTextCtrl(page1, wxID_ANY, "", wxPoint(10, 33), wxSize(30, -1));
    wxStaticText* tab1_x1 = new wxStaticText(page1, wxID_ANY, "x1", wxPoint(180, 10));
    wxChoice* opChoice1 = new wxChoice(page1, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(op_choices) / sizeof(op_choices[0]), op_choices);

    x2para_ctrl = new wxTextCtrl(page1, wxID_ANY, "", wxPoint(10, 33), wxSize(30, -1));
    wxStaticText* tab1_x2 = new wxStaticText(page1, wxID_ANY, "x2", wxPoint(220, 10));
    wxChoice* opChoice2 = new wxChoice(page1, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(op_choices) / sizeof(op_choices[0]), op_choices);

    x3para_ctrl = new wxTextCtrl(page1, wxID_ANY, "", wxPoint(10, 33), wxSize(30, -1));
    wxStaticText* tab1_x3 = new wxStaticText(page1, wxID_ANY, "x3", wxPoint(260, 10));
    wxChoice* opChoice3 = new wxChoice(page1, wxID_ANY, wxDefaultPosition, wxDefaultSize, sizeof(op_choices) / sizeof(op_choices[0]), op_choices);

    x4para_ctrl = new wxTextCtrl(page1, wxID_ANY, "", wxPoint(10, 33), wxSize(30, -1));
    wxStaticText* tab1_x4 = new wxStaticText(page1, wxID_ANY, "x4", wxPoint(300, 10));

    sizerObjective->Add(m_radioBoxObjective, 0, wxALL, 5);
    sizerObjective->Add(Z, 0, wxALL | wxALL, 5);
    sizerObjective->Add(x1para_ctrl, 0, wxALL, 5);
    sizerObjective->Add(tab1_x1, 0, wxALL | wxALL, 5);
    sizerObjective->Add(opChoice1, 0, wxALL, 5);
    sizerObjective->Add(x2para_ctrl, 0, wxALL, 5);
    sizerObjective->Add(tab1_x2, 0, wxALL | wxALL, 5);
    sizerObjective->Add(opChoice2, 0, wxALL, 5);
    sizerObjective->Add(x3para_ctrl, 0, wxALL, 5);
    sizerObjective->Add(tab1_x3, 0, wxALL | wxALL, 5);
    sizerObjective->Add(opChoice3, 0, wxALL, 5);
    sizerObjective->Add(x4para_ctrl, 0, wxALL, 5);
    sizerObjective->Add(tab1_x4, 0, wxALL | wxALL, 5);

    wxButton* button = new wxButton(page1, wxID_ANY, "Calculate");
    m_resultText = new wxStaticText(page1, wxID_ANY, "");

    boxSizer1->Add(sizerObjective, 0, wxALL, 5);
    boxSizer1->Add(button, 0, wxALL, 5);
    boxSizer1->Add(m_resultText, 0, wxALL, 5);

    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    panel2 = new wxScrolledWindow(page1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
    panel2->SetScrollRate(5, 5);

    wxStaticBox* box2 = new wxStaticBox(panel2, wxID_ANY, "Constraints");
    wxStaticBoxSizer* boxSizer2 = new wxStaticBoxSizer(box2, wxVERTICAL);

    con_spinctrl = new wxSpinCtrl(panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(50, -1));
    con_spinctrl->SetRange(1, 20);
    gener_con_btn = new wxButton(panel2, wxID_ANY, "Generate Constraints");

    gener_con_btn->Bind(wxEVT_BUTTON, &MainFrame::Generate_con, this);

    sizerConstraints = new wxBoxSizer(wxVERTICAL);

    boxSizer2->Add(sizerConstraints, 1, wxEXPAND | wxALL, 5);
    boxSizer2->Add(con_spinctrl, 0, wxALL, 5);
    boxSizer2->Add(gener_con_btn, 0, wxALL, 5);

    panel2->SetSizer(boxSizer2);
    boxSizer2->Fit(panel2);

    boxSizer1->Add(panel2, 1, wxEXPAND | wxALL, 5);

    page1->SetSizer(boxSizer1);
    m_notebook->AddPage(page1, "Linear Programming");
}

void MainFrame::CreateNLP_Tab() {
    wxPanel* page2 = new wxPanel(m_notebook);
    wxStaticBox* box2Tab2 = new wxStaticBox(page2, wxID_ANY, "Non-Linear Programming Example");
    wxStaticBoxSizer* boxSizer2Tab2 = new wxStaticBoxSizer(box2Tab2, wxVERTICAL);

    wxStaticText* tab2Text = new wxStaticText(page2, wxID_ANY, "This is Tab 2");
    boxSizer2Tab2->Add(tab2Text, 0, wxALL, 5);

    page2->SetSizer(boxSizer2Tab2);
    m_notebook->AddPage(page2, "Non-Linear Programming");
}

void MainFrame::SetupMainSizer() {
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_notebook, 1, wxEXPAND | wxALL, 5);
    panel->SetSizer(sizer);
}


