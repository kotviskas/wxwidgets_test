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
    nrows = 5; ncols = 3;
    gridTable = new MyGridTable(5, 3, m_grid1);
    for (int row = 0; row < gridTable->GetNumberRows(); ++row) {
        for (int col = 0; col < gridTable->GetNumberCols(); ++col) {
            if (col == 0) {
                gridTable->SetValue(row, col, wxString::Format("Row %d, Col %d", row + 1, col + 1));
            }
            else if (col == 1) {
                // Пример: Четные строки с изображением, нечетные без
                wxString imageValue = (row % 2 == 0) ? "1" : "0";
                gridTable->SetValue(row, col, imageValue);
                m_grid1->SetReadOnly(row, col, true);
            }
            else if (col == 2) {
                // Пример: Четные столбцы с флажками, нечетные без
                wxString checkboxValue = (row % 2 == 0) ? "1" : "0";
                gridTable->SetValue(row, col, checkboxValue);
            }
        }
    }
    m_grid1->SetTable(gridTable, true, wxGrid::wxGridSelectRows);
    //wxGridCellBoolEditor* boolEditor = new wxGridCellBoolEditor();
    for (int row = 0; row < gridTable->GetNumberRows(); ++row) {
        m_grid1->SetCellRenderer(row, 1, new ImageRenderer());
        m_grid1->SetReadOnly(row, 1, true);
        m_grid1->SetReadOnly(row, 0, true);
    }
    //m_grid1->SetCellEditor(0, 2, boolEditor);
    // Rows
    m_grid1->SetRowLabelSize(0);
    
    wxDataViewCtrl* dataViewCtrl = new wxDataViewCtrl(m_panel6, ID_MUSIC_CTRL, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_NO_HEADER);
    treeModel = new TreeModel;
    dataViewCtrl->AssociateModel(treeModel.get());
    //m_music_model = new MusicModel;
    //dataViewCtrl->AssociateModel(m_music_model.get());
    wxDataViewColumn* col1 = new wxDataViewColumn("Column 1", new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT), 0, wxCOL_WIDTH_AUTOSIZE);
    dataViewCtrl->AppendColumn(col1);
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

void guiMainFrame::OnNameSort(wxCommandEvent& event)
{
    isNameSorted = !isNameSorted;
    gridTable->SortByName(isNameSorted);
}

void guiMainFrame::OnImageFilter(wxCommandEvent& event)
{
    isFilterImage = !isFilterImage;
    gridTable->FilterByImage(isFilterImage);
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

void guiMainFrame::UpdateGrid()
{
    m_grid1->SetTable(nullptr);
    MyGridTable* myGridTable = dynamic_cast<MyGridTable*>(m_grid1->GetTable());

    if (myGridTable) {
        myGridTable->SetData(gridTable->GetData());
        for (int row = 0; row < gridTable->GetNumberRows(); ++row) {
            m_grid1->SetCellRenderer(row, 1, new ImageRenderer());
            m_grid1->SetReadOnly(row, 1, true);
            m_grid1->SetReadOnly(row, 0, true);
        }
    }
    else {
        
    }
    m_grid1->ForceRefresh(); 
    m_grid1->Update();
    m_grid1->AutoSizeColumns();
    m_grid1->Layout();
}


wxTreeItemId guiMainFrame::tree_add(const wxTreeItemId& parent, const wxString& text, int tree_node)
{
    wxTreeItemId id = m_treeCtrl1->AppendItem(parent, text);
    tree_data.insert(std::pair<int, wxTreeItemId>(tree_node, id));
    return id;
}

