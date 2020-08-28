//
// Created by wang on 2020/7/7.
//
#include "BlueSide.h"
#include "BlueSideApp.h"
#include <BlueSideCallerPage.h>
#include <iostream>
#include <thread>

using std::string;
using std::thread;

void sendEvent(){
    //quequeEvent
    auto* test = (BlueSideApp *)wxApp::GetInstance();
    if(test->IsActive()){
        std::cout << "active" << std::endl;
        auto* curFrame = (BlueSideCallerPage *)test->GetTopWindow();
        auto testStr = "test";
//        curFrame->CallAfter(&BlueSideCallerPage::testCallAfter, testStr);

//        test->switchPage(curFrame->GetId(), &BlueSideCallerPage::testCallAfter);
    }
//    wxGetApp().CallAfter(&BlueSideApp::test);
}

void test(){
    std::cout << "run test" << std::endl;
    sendEvent();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void testThread(){
    thread t(&test);
    t.detach();
}
