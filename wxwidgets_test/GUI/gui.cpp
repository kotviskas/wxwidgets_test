///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_main = new wxMenuBar( 0 );
	m_main->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxEmptyString ) );
	m_main->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_main->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	menu_file = new wxMenu();
	m_main->Append( menu_file, _("File") );

	menu_edit = new wxMenu();
	m_main->Append( menu_edit, _("Edit") );

	menu_view = new wxMenu();
	m_main->Append( menu_view, _("View") );

	menu_help = new wxMenu();
	m_main->Append( menu_help, _("Help") );

	this->SetMenuBar( m_main );

	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_statusBar1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	t_main = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	t_main->SetToolBitmapSize( wxSize( 16,16 ) );
	t_main->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	t_main->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );

	tool_add = t_main->AddTool( wxID_ANY, _("Add"), wxArtProvider::GetBitmap( wxART_GO_HOME, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	tool_print = t_main->AddTool( wxID_ANY, _("Print"), wxArtProvider::GetBitmap( wxART_GO_FORWARD, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	t_main->Realize();

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_splitter2 = new wxSplitterWindow( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter2OnIdle ), NULL, this );

	m_splitter2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	m_splitter2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );

	m_panel5 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel5->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	m_notebook2 = new wxNotebook( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_BOTTOM );
	m_notebook2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	m_notebook2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );

	m_panel7 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel7->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_treeCtrl1 = new wxTreeCtrl( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_treeCtrl1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer6->Add( m_treeCtrl1, 1, wxEXPAND, 0 );


	m_panel7->SetSizer( bSizer6 );
	m_panel7->Layout();
	bSizer6->Fit( m_panel7 );
	m_notebook2->AddPage( m_panel7, _("Project"), false );
	m_panel8 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );


	m_panel8->SetSizer( bSizer7 );
	m_panel8->Layout();
	bSizer7->Fit( m_panel8 );
	m_notebook2->AddPage( m_panel8, _("Elements"), true );
	m_panel9 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_splitter21 = new wxSplitterWindow( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter21->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter21OnIdle ), NULL, this );

	m_panel81 = new wxPanel( m_splitter21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );


	m_panel81->SetSizer( bSizer71 );
	m_panel81->Layout();
	bSizer71->Fit( m_panel81 );
	m_panel91 = new wxPanel( m_splitter21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );

	m_toolBar2 = new wxToolBar( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL );
	m_tool3 = m_toolBar2->AddTool( wxID_ANY, _("tool"), wxArtProvider::GetBitmap( wxART_GO_UP, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool4 = m_toolBar2->AddTool( wxID_ANY, _("tool"), wxArtProvider::GetBitmap( wxART_GO_DOWN, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar2->Realize();

	bSizer81->Add( m_toolBar2, 0, wxEXPAND, 0 );

	m_grid1 = new wxGrid( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid1->CreateGrid( 1, 1 );
	m_grid1->EnableEditing( true );
	m_grid1->EnableGridLines( true );
	m_grid1->EnableDragGridSize( false );
	m_grid1->SetMargins( 0, 0 );

	// Columns
	m_grid1->EnableDragColMove( false );
	m_grid1->EnableDragColSize( true );
	m_grid1->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid1->EnableDragRowSize( true );
	m_grid1->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer81->Add( m_grid1, 1, wxALL|wxEXPAND, 0 );


	m_panel91->SetSizer( bSizer81 );
	m_panel91->Layout();
	bSizer81->Fit( m_panel91 );
	m_splitter21->SplitHorizontally( m_panel81, m_panel91, 175 );
	bSizer8->Add( m_splitter21, 1, wxEXPAND, 0 );


	m_panel9->SetSizer( bSizer8 );
	m_panel9->Layout();
	bSizer8->Fit( m_panel9 );
	m_notebook2->AddPage( m_panel9, _("Layout"), false );

	bSizer51->Add( m_notebook2, 1, wxEXPAND, 0 );


	m_panel5->SetSizer( bSizer51 );
	m_panel5->Layout();
	bSizer51->Fit( m_panel5 );
	m_panel6 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel6->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel6->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_splitter2->SplitVertically( m_panel5, m_panel6, 364 );
	bSizer2->Add( m_splitter2, 1, wxEXPAND, 0 );


	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer5->Add( m_panel1, 1, wxEXPAND, 0 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}
