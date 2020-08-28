///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jun  1 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/colour.h>
#include <wx/font.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/imaglist.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>

///////////////////////////////////////////////////////////////////////////

wxDECLARE_EVENT(MY_EVENT, wxCommandEvent);

///////////////////////////////////////////////////////////////////////////////
/// Class CallerPage
///////////////////////////////////////////////////////////////////////////////
class CallerPage : public wxFrame {
 private:
 protected:
  wxButton* callBtn;
  wxBitmapToggleButton* beSpeaker;

  // Virtual event handlers, overide them in your derived class
  virtual void makeCall(wxCommandEvent& event) { event.Skip(); }
  virtual void closeWindow(wxCloseEvent& event) {event.Skip(); }
  virtual void test(wxCommandEvent& event) { event.Skip(); }
  virtual void testCallAfter(wxCommandEvent &event){event.Skip();}


 public:
  CallerPage(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString,
             const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300, 500),
             long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

  ~CallerPage();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MeetingPage
///////////////////////////////////////////////////////////////////////////////
class MeetingPage : public wxFrame
{
private:

protected:
    wxPanel* playerView;
    wxPanel* stateView;
    wxBitmapToggleButton* beSpeaker;
    wxBitmapButton* exitBtn;
    wxListCtrl* userListBox;
    wxSlider* volumnSlider;

    virtual void test(wxCommandEvent& event) { event.Skip(); }
    virtual void onScroll(wxScrollEvent & event){}

public:

    MeetingPage( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    ~MeetingPage();

};
