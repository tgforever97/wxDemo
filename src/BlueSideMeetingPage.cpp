#include "BlueSideMeetingPage.h"
#include <wx/wx.h>

BlueSideMeetingPage::BlueSideMeetingPage( wxWindow* parent )
:MeetingPage( parent )
{
    this->SetTitle("房间10001");
//    wxPaintDC dc(stateView);
//    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
//                false, wxEmptyString);
//    dc.SetFont(font);
//    dc.SetTextForeground(*wxWHITE);
//    dc.DrawText("编码时延：null", wxPoint(10, 10));
//    dc.DrawText("解码时延：null", wxPoint(170, 10));
//    dc.DrawText("网络时延：null" , wxPoint(330, 10));
//    dc.DrawText("收包数量：0", wxPoint(10, 40));
//    dc.DrawText("发包数量：0" , wxPoint(170, 40));
//    stateView->Layout();
}

static int wxCALLBACK compareUserId(wxIntPtr item1, wxIntPtr item2, wxIntPtr sortData)
{
    if (item1 < item2)
        return -1;
    if (item1 > item2)
        return 1;

    return 0;
}

void BlueSideMeetingPage::test(wxCommandEvent &event) {
//    auto pos = userListBox->FindItem(0, "wangmengyuan");
////    userListBox->SetItemImage(pos, 1);
//    std::cout << "click" << pos << std::endl;
//    if(pos > -1){
//        userListBox->DeleteItem(pos);
//    }
    auto list = {"cehngqi","liruijie","zhangshiting"};
    long userId = 0l;
    for(const auto& l : list){
        userId++;
        wxListItem item;
        item.SetId(0);
        item.SetImage(0);
        item.SetText(l);
        item.SetData(userId);
        userListBox->InsertItem(item);
    }
    userListBox->SortItems(compareUserId, 0);

//    auto text = new wxStaticText (playerView, wxID_ANY, "hello", wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE);
//    text->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,
//                false, wxEmptyString));
//    //    text->SetForegroundColour(*wxWHITE);
//    playerView->Layout();
//    userListBox->DeleteItem(0);
//    userListBox->Refresh();
}

void BlueSideMeetingPage::onScroll(wxScrollEvent &event) {
    auto fill = volumnSlider->GetValue();
    std::cout << "123 " << fill << std::endl;
}
