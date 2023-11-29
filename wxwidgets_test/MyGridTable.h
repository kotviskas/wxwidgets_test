#pragma once
#include <wx/wx.h>
#include <wx/grid.h>
#include "ImageRenderer.h"

class MyGridTable : public wxGridTableBase
{
public:
    MyGridTable(int numRows, int numCols, wxGrid* grid);
    ~MyGridTable()
    {
        data.clear();
    }
    int GetNumberRows() override;
    int GetNumberCols() override;
    wxString GetValue(int row, int col) override;
    void SetValue(int row, int col, const wxString& value) override;
    wxString GetColLabelValue(int col) override;
    wxString GetTypeName(int row, int col) override;
    void ClearData();
    void AppendRow(const wxString& text, const wxString& image, const wxString& checkbox);
    bool DeleteRows(size_t pos, size_t numRows) override;
    void Clear() override;
    void SetData(const std::vector<std::vector<wxString>>& newData);
    bool AppendRows(size_t numRows) override;
    void SortByName(bool isNameSorted);
    void FilterByImage(bool isOnlyWithImage);
    const std::vector<std::vector<wxString>>& GetData() const;

private:
    int numRows;
    int numCols;
    wxGrid* grid;
    std::vector<std::vector<wxString>> data;
};