#pragma once
#include <wx/wx.h>
#include <wx/grid.h>

class ImageRenderer : public wxGridCellRenderer
{
public:
    ImageRenderer() : wxGridCellRenderer() {};
    void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected) override;
    wxGridCellRenderer* Clone() const override;
    wxSize GetBestSize(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, int row, int col) override;
};
