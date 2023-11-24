#include "App.h"
#include "gui/guiMainFrame.h"
#include "gui/gui.h"

IMPLEMENT_APP(App)

App::App() {
}

App::~App() {
}

bool App::OnInit() {
	guiMainFrame* frame = new guiMainFrame((wxWindow*)NULL);

	//Установка иконки приложения
	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap appIconBitmap(wxT("app_icon.png"), wxBITMAP_TYPE_PNG);
	wxIcon appIcon;
	appIcon.CopyFromBitmap(appIconBitmap);

	frame->SetIcon(appIcon);
	frame->Show();
	//frame->SetBackgroundColour(*wxBLACK);
	SetTopWindow(frame);
	//wxPanel* panel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, frame->GetSize());
	//panel->SetBackgroundColour(*wxBLACK);
	return true;
}

wxPanel* App::BuildColorPanel(wxWindow* parent)
{
	auto panel = new wxPanel(parent, wxID_ANY);
	panel->SetBackgroundColour(*wxBLACK);
	return panel;
}
