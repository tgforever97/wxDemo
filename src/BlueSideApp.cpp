/**
  theia3 client implement

  @project BlueSide
  @author sk88
  @since 2020/6/1
  @version v0.0.1 2020/6/1
*/

#include <iostream>
#include <memory>
#include "BlueSideApp.h"
#include "BlueSideCallerPage.h"
#include "BlueSideMeetingPage.h"

extern void testThread();

bool BlueSideApp::OnInit() {
  //初始化
  std::cout << "Welcome to use BlueSide!" << std::endl;
  auto* frame = new BlueSideMeetingPage(nullptr);
  frame->Show(true);
//  testThread();
  return true;
}

#ifdef _WIN32
int main() {
  BlueSideApp *app = new BlueSideApp();
  wxApp::SetInstance(app);
  return wxEntry();
}
#else
IMPLEMENT_APP(BlueSideApp);
#endif

//void BlueSideApp::switchPage(wxWindowID id) {
//    if (this->IsActive()) {
//        auto* curFrame = this->GetTopWindow();
//        if (curFrame->GetId() == id) {
//            curFrame->CallAfter(fn);
//        }
//    }
//}

