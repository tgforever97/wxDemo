#ifndef __BlueSideMeetingPage__
#define __BlueSideMeetingPage__

/**
@file
Subclass of MeetingPage, which is generated by wxFormBuilder.
*/

#include "BlueSide.h"

//// end generated include

/** Implementing MeetingPage */
class BlueSideMeetingPage : public MeetingPage
{

    protected:
        void test(wxCommandEvent& event);
        void onScroll(wxScrollEvent & event) override;
	public:
		/** Constructor */
		BlueSideMeetingPage( wxWindow* parent );
	//// end generated class members


};

#endif // __BlueSideMeetingPage__
