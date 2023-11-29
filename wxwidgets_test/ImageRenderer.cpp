#include "ImageRenderer.h"
    void ImageRenderer::Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected)
    {
        wxGridCellRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

        // �������� �������� �� ������
        wxString value = grid.GetCellValue(row, col);
        wxBitmap bitmap;
        if (value == "1")
        {
            bitmap.Create(16, 16);
            wxMemoryDC dcMem;
            dcMem.SelectObject(bitmap);
            dcMem.SetBackground(*wxRED_BRUSH);
            dcMem.Clear();
            dcMem.SelectObject(wxNullBitmap);
        }

        // ������������ �����������
        if (bitmap.IsOk())
        {
            dc.DrawBitmap(bitmap, rect.x, rect.y, true);
        }
    }

    wxGridCellRenderer* ImageRenderer::Clone() const
    {
        return new ImageRenderer(*this);
    }

    wxSize ImageRenderer::GetBestSize(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, int row, int col)
    {
        // ���������� ���� �����, ����� ������� ����������� ������ ��� ������
        return wxSize(20, 20); // ��������� ������ �����������
    }