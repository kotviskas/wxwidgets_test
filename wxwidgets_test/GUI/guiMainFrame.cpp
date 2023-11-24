#include "guiMainFrame.h"
#include <wx/msgdlg.h>
enum
{
    ID_About = 1,
    ID_MUSIC_CTRL = 50
};

guiMainFrame::guiMainFrame(wxWindow* parent)
	:
	MainFrame(parent)
{
    //toolbar
	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap add_bitmap(wxT("add.png"), wxBITMAP_TYPE_PNG);
	wxBitmap print_bitmap(wxT("print.png"), wxBITMAP_TYPE_PNG);
	tool_add->SetNormalBitmap(add_bitmap);
	tool_print->SetNormalBitmap(print_bitmap);
    t_main->Realize();

    //treectrl
    build_tree();

    //menu
    menu_file_close = new wxMenu();
    wxMenuItem* menu_file_closeItem = new wxMenuItem(menu_file, wxID_EXIT, "&Close program\tCtrl+W");
    menu_file->Append(menu_file_closeItem);
    menu_help_about = new wxMenu();
    wxMenuItem* menu_help_abouItem = new wxMenuItem(menu_help, ID_About, "&About program");
    menu_help->Append(menu_help_abouItem);

    Bind(wxEVT_MENU, &guiMainFrame::OnQuit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &guiMainFrame::OnAbout, this, ID_About);

    // Grid
    int nrows, ncols;
    nrows = 2; ncols = 2;

    LayoutGridItem item1;
    item1.name = "1";
    item1.icon = add_bitmap;
    item1.checkbox = false;

    m_grid1->AppendCols(ncols);
    m_grid1->AppendRows(nrows);
    m_grid1->EnableEditing(true);
    m_grid1->EnableGridLines(true);
    // Columns
    m_grid1->SetColLabelValue(0, _("name"));
    m_grid1->SetColLabelValue(1, _("art"));
    m_grid1->SetColLabelValue(2, _("checkbox"));
    // Rows
    m_grid1->SetRowLabelSize(0);

    m_grid1->SetCellValue(0, 0, "name");

    /*
    wxDataViewTextRenderer* tr =
        new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT);
    wxDataViewColumn* column0 =
        new wxDataViewColumn("title", tr, 0, 200, wxALIGN_LEFT,
            wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_RESIZABLE);*/
    
    wxDataViewCtrl* dataViewCtrl = new wxDataViewCtrl(m_panel6, ID_MUSIC_CTRL, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_NO_HEADER);
    //dataModel = new MyDataModel;
    //dataViewCtrl->AssociateModel(static_cast<wxDataViewModel*>(dataModel.get()));
    
    treeModel = new TreeModel;
    dataViewCtrl->AssociateModel(treeModel.get());
    
    //m_music_model = new MusicModel;
    //dataViewCtrl->AssociateModel(m_music_model.get());
   
    
    //treeStore = new TreeStoreModel;
    //dataViewCtrl->AssociateModel(treeStore.get());
    //wxDataViewItem rootItem(static_cast<void*>(treeStore->GetRootItem()));
    //dataViewCtrl->AppendContainer(rootItem, "Root");

    //wxDataViewColumn* col1 = new wxDataViewColumn("Column 1", new wxDataViewTextRenderer(), 0, wxCOL_WIDTH_AUTOSIZE);
    wxDataViewColumn* col1 = new wxDataViewColumn("Column 1", new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT), 0, wxCOL_WIDTH_AUTOSIZE);
    //wxDataViewColumn* col2 = new wxDataViewColumn("Column 2", new wxDataViewTextRenderer("long", wxDATAVIEW_CELL_INERT), 1, wxCOL_WIDTH_AUTOSIZE);
    dataViewCtrl->AppendColumn(col1);
    //dataViewCtrl->AppendColumn(col2);

    wxSizer* firstPanelSz = new wxBoxSizer(wxVERTICAL);
    dataViewCtrl->SetMinSize(wxSize(-1, 200));
    firstPanelSz->Add(dataViewCtrl, 1, wxEXPAND);
    m_panel6->SetSizerAndFit(firstPanelSz);
}

void guiMainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void guiMainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox("This is information about app",
        "Title", wxOK | wxICON_INFORMATION);
}

void guiMainFrame::build_tree()
{
    wxTreeItemId root = m_treeCtrl1->AddRoot("Project");
    wxTreeItemId design_notes = m_treeCtrl1->AppendItem(root, "Design Notes");
    wxTreeItemId options = m_treeCtrl1->AppendItem(root, "Project Options");
    wxTreeItemId definitions = m_treeCtrl1->AppendItem(root, "Global Definitions");

    wxTreeItemId options1 = m_treeCtrl1->AppendItem(options, "Options 1");
    wxTreeItemId options2 = m_treeCtrl1->AppendItem(options, "Options 2");

    wxTreeItemId definitions1 = m_treeCtrl1->AppendItem(definitions, "Definitions1");
    wxTreeItemId definitions2 = m_treeCtrl1->AppendItem(definitions, "Definitions2");

    tree_add(design_notes, "0", 0);

    tree_add(options, "1", 1);
    tree_add(options1, "2", 2);
    tree_add(options1, "3", 3);
    root = tree_add(options2, "4", 4);
    tree_add(root, "5", 5);
    tree_add(options2, "6", 6);

    root = tree_add(definitions1, "7", 7);
    tree_add(root, "8", 8);
    tree_add(definitions1, "9", 9);
    tree_add(definitions1, "10", 10);

    root = tree_add(definitions2, "11", 11);
    tree_add(root, "12", 12);
    tree_add(root, "13", 13);
    tree_add(definitions2, "14", 14);
}

wxTreeItemId guiMainFrame::tree_add(const wxTreeItemId& parent, const wxString& text, int tree_node)
{
    wxTreeItemId id = m_treeCtrl1->AppendItem(parent, text);
    tree_data.insert(std::pair<int, wxTreeItemId>(tree_node, id));
    return id;
}
