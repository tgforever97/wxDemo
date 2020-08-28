#include "BlueSideCallerPage.h"
#include <BlueSideMeetingPage.h>
#include <wx/msgdlg.h>


BlueSideCallerPage::BlueSideCallerPage(wxWindow* parent)
    : CallerPage(parent) {
}

void BlueSideCallerPage::makeCall(wxCommandEvent& event) {
}

void BlueSideCallerPage::closeWindow(wxCloseEvent& event) {
}

void BlueSideCallerPage::test(wxCommandEvent &event) {
    std::cout << "test" << beSpeaker->GetValue() <<std::endl;
    if(beSpeaker->GetValue()){
        std::cout << "press" <<std::endl;
    }else{
        std::cout << "up" <<std::endl;
    }
}

void BlueSideCallerPage::testCallAfter(std::string& msg) {
    std::cout << "response" << std::endl;
    auto* frame = new BlueSideMeetingPage(nullptr);
    frame->Show(true);
    this->Destroy();
}
