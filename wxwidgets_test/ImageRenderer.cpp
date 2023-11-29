#include "ImageRenderer.h"
    void ImageRenderer::Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected)
    {
        wxGridCellRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

        // Получаем значение из ячейки
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

        // Отрисовываем изображение
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
        // Реализуйте этот метод, чтобы вернуть оптимальный размер для ячейки
        return wxSize(20, 20); // Примерный размер изображения
    }