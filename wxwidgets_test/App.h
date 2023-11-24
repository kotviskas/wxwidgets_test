#pragma once

#ifndef TESTAPP_H
#define TESTAPP_H

#include <wx/wx.h>

class App : public wxApp {
public:
	App();
	virtual ~App();
	virtual bool OnInit();
	wxPanel* BuildColorPanel(wxWindow* parent);
};

DECLARE_APP(App)

#endif