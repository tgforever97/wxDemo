//
// Created by wang on 2020/6/1.
//

#ifndef BLUESIDE_BLUESIDEAPP_H
#define BLUESIDE_BLUESIDEAPP_H

#include <wx/wx.h>

class BlueSideApp : public wxApp{
public:
    virtual bool OnInit();
//    template <typename T>
//    void switchPage(wxWindowID id, const T& fn);
};

DECLARE_APP(BlueSideApp)

#endif //BLUESIDE_BLUESIDEAPP_H
