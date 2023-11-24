#pragma once
#ifndef __guiMyFrame__
#define __guiMyFrame__

/**
@file
Subclass of MyFrame, which is generated by wxFormBuilder.
*/

#include "gui.h"
#include <map>
#include "wx/dataview.h"
#include "../models.h"
#include "../newmodel.h"
#include "../treeModel.h"
#include "../treeStore.h"

//// end generated include

/** Implementing MyFrame */
class guiMainFrame : public MainFrame
{
	public:
		guiMainFrame( wxWindow* parent );
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void build_tree();

		wxMenu* menu_file_close;
		wxMenu* menu_help_about;
		wxTreeItemId tree_add(const wxTreeItemId& parent, const wxString& text, int tree_node);
		void MyGridCellRenderer(wxGrid& grid,
			wxGridCellAttr& attr,
			wxDC& dc,
			const wxRect& rect,
			int row, int col,
			bool isSelected);
		std::map<int, wxTreeItemId> tree_data;

		wxObjectDataPtr<MusicModel> m_music_model;
		wxObjectDataPtr<MyDataModel> dataModel;
		wxObjectDataPtr<TreeModel> treeModel;
		wxObjectDataPtr<TreeStoreModel> treeStore;
		wxDataViewColumn* m_col;
		wxDataViewCtrl* m_ctrl;
};

class LayoutGridItem
{
public:
	std::string name;
	wxBitmap icon;
	bool checkbox;
};
#endif // __guiMyFrame__
