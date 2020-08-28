///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jun  1 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BlueSide.h"
#include <wx/wx.h>

wxDEFINE_EVENT(MY_EVENT, wxCommandEvent);

CallerPage::CallerPage(wxWindow *parent, wxWindowID id, const wxString &title,
                       const wxPoint &pos, const wxSize &size, long style)
    : wxFrame(parent, id, title, pos, size, style) {

    wxImage::AddHandler(new wxPNGHandler);
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer3;
    bSizer3 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer6;
    bSizer6 = new wxBoxSizer(wxVERTICAL);

    bSizer6->SetMinSize(wxSize(300, 400));
    bSizer6->Add(-1, 30);

    //test listctrl
    auto userList = new wxListView(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLC_REPORT);

    bSizer6->Add(userList, 0, wxEXPAND | wxALL, 5);
    bSizer3->Add(bSizer6, 0, wxEXPAND, 10);

    auto btnBmp = wxBitmap(_T("img/microphone.png"), wxBITMAP_TYPE_PNG);
    auto btnPressedBmp = wxBitmap(_T("img/microphone-slash.png"), wxBITMAP_TYPE_PNG);
    beSpeaker = new wxBitmapToggleButton(this, wxID_ANY, btnBmp, wxDefaultPosition, wxSize(30, 30), wxBORDER_NONE);
    beSpeaker->SetBitmapPressed(btnPressedBmp);
    bSizer3->Add(beSpeaker, 0, wxALIGN_CENTER_HORIZONTAL, 0);


    this->SetSizer(bSizer3);
    this->Layout();

    this->Centre(wxBOTH);

    beSpeaker->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CallerPage::test),
                       NULL, this);

    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CallerPage::closeWindow),
                  NULL, this);
}

CallerPage::~CallerPage() {
    // Disconnect Events
    callBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(CallerPage::makeCall), NULL, this);
}

MeetingPage::MeetingPage(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    wxImage::AddHandler(new wxPNGHandler);

    wxBoxSizer *meetingSizer;
    meetingSizer = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *playerSizer;
    playerSizer = new wxBoxSizer(wxVERTICAL);
    playerSizer->SetMinSize(wxSize(600, 500));

    playerView = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    playerView->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    playerSizer->Add(playerView, 4, wxALL | wxEXPAND, 10);

    stateView = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    stateView->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    playerSizer->Add(stateView, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

    wxBoxSizer *playerBtnSizer;
    playerBtnSizer = new wxBoxSizer(wxHORIZONTAL);

    auto btnBmp = wxBitmap(_T("img/microphone.png"), wxBITMAP_TYPE_PNG);
    auto btnPressedBmp = wxBitmap(_T("img/microphone-slash.png"), wxBITMAP_TYPE_PNG);
    beSpeaker = new wxBitmapToggleButton(this, wxID_ANY, btnBmp, wxDefaultPosition, wxSize(30, 30), wxBORDER_NONE);
    beSpeaker->SetBitmapPressed(btnPressedBmp);

    playerBtnSizer->Add(beSpeaker, 0, wxALIGN_CENTER_VERTICAL, 0);
    playerBtnSizer->Add(30, 0, 1, wxEXPAND, 5);

    auto exitBmp = wxBitmap(_T("img/hungup.png"), wxBITMAP_TYPE_PNG);
    exitBtn = new wxBitmapButton(this, wxID_ANY, exitBmp, wxDefaultPosition, wxSize(30, 30), wxBORDER_NONE);
    exitBtn->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

    playerBtnSizer->Add(exitBtn, 0, wxALIGN_CENTER_VERTICAL, 0);
    playerBtnSizer->Add(30, 0, 1, wxEXPAND, 5);

    volumnSlider = new wxSlider(this, wxID_ANY, 0, 0, 10, wxDefaultPosition, wxSize(100, -1), wxSL_HORIZONTAL | wxSL_VALUE_LABEL);
    volumnSlider->Bind(wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(MeetingPage::onScroll), this);
    playerBtnSizer->Add(volumnSlider, 0, wxALIGN_CENTER_VERTICAL, 0);

    playerSizer->Add(playerBtnSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5);


    meetingSizer->Add(playerSizer, 4, wxEXPAND, 0);

    wxBoxSizer *listSizer;
    listSizer = new wxBoxSizer(wxVERTICAL);

    listSizer->SetMinSize(wxSize(200, 500));
    auto userImage = new wxImageList(30, 31, true, 1);
    userImage->Add(wxBitmap(_T("img/offMike.png"), wxBITMAP_TYPE_PNG));
    //    userImage->Add(wxBitmap(_T("img/test.png"), wxBITMAP_TYPE_PNG));
    userListBox = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(200, -1),
                                 wxLC_REPORT | wxBORDER_NONE);
    userListBox->SetImageList(userImage, wxIMAGE_LIST_SMALL);
    userListBox->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    userListBox->InsertColumn(0, "", wxLIST_FORMAT_LEFT, 200);
    wxListItem item1;
    item1.SetId(0);
    item1.SetImage(0);
    item1.SetText(wxT("wangmengyuan"));
    item1.SetData(100l);
    userListBox->InsertItem(item1);
    userListBox->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

    auto userListLabel =
            new wxStaticText(this, wxID_ANY, "麦下用户（0），麦上用户（0）", wxDefaultPosition,
                             wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    userListLabel->SetFont(
            wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    listSizer->Add(userListLabel, 0, wxEXPAND | wxRIGHT | wxTOP, 10);
    listSizer->Add(-1, 10);

    listSizer->Add(userListBox, 1, wxEXPAND | wxTOP, 10);


    meetingSizer->Add(listSizer, 1, wxEXPAND, 0);


    this->SetSizer(meetingSizer);
    this->Layout();

    this->Centre(wxBOTH);
    exitBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MeetingPage::test),
                     NULL, this);
}

MeetingPage::~MeetingPage() {
    volumnSlider->Unbind(wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(MeetingPage::onScroll), this);
    exitBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MeetingPage::test),
                        NULL, this);
}
