///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/tglbtn.h>
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_main;
		wxMenu* menu_file;
		wxMenu* menu_edit;
		wxMenu* menu_view;
		wxMenu* menu_help;
		wxStatusBar* m_statusBar1;
		wxToolBar* t_main;
		wxToolBarToolBase* tool_add;
		wxToolBarToolBase* tool_print;
		wxPanel* m_panel1;
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel5;
		wxNotebook* m_notebook2;
		wxPanel* m_panel7;
		wxTreeCtrl* m_treeCtrl1;
		wxPanel* m_panel8;
		wxPanel* m_panel9;
		wxSplitterWindow* m_splitter21;
		wxPanel* m_panel81;
		wxPanel* m_panel91;
		wxToolBar* m_toolBar2;
		wxBitmapToggleButton* m_bmToggleBtn1;
		wxBitmapToggleButton* m_bmToggleBtn2;
		wxGrid* m_grid1;
		wxPanel* m_panel6;

		// Virtual event handlers, override them in your derived class
		virtual void OnNameSort( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImageFilter( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 364 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter2OnIdle ), NULL, this );
		}

		void m_splitter21OnIdle( wxIdleEvent& )
		{
			m_splitter21->SetSashPosition( 175 );
			m_splitter21->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter21OnIdle ), NULL, this );
		}

};

