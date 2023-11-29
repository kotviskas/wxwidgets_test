#include "MyGridTable.h"

MyGridTable::MyGridTable(int numRows, int numCols, wxGrid* grid)
    : numRows(numRows), numCols(numCols), grid(grid)
{
    data.resize(numRows, std::vector<wxString>(numCols, wxEmptyString));
}

int MyGridTable::GetNumberRows()
{
    return numRows;
}

int MyGridTable::GetNumberCols()
{
    return numCols;
}

wxString MyGridTable::GetValue(int row, int col)
{
    if (row < 0 || row >= numRows || col < 0 || col >= numCols)
        return wxEmptyString;

    return data[row][col];
}

void MyGridTable::SetValue(int row, int col, const wxString& value)
{
    if (row >= 0 && row < numRows && col >= 0 && col < numCols)
    {
        data[row][col] = value;
        grid->Refresh();
    }
}

wxString MyGridTable::GetColLabelValue(int col)
{
    if (col == 0)
        return "Text";
    else if (col == 1)
        return "Image";
    else if (col == 2)
        return "Checkbox";

    return "";
}

wxString MyGridTable::GetTypeName(int row, int col)
{
    if (col == 0)
        return wxGRID_VALUE_STRING;
    else if (col == 1)
        return wxGRID_VALUE_STRING;
    else if (col == 2)
        return "bool";

    return "";
}

void MyGridTable::ClearData()
{
    data.clear();
}

void MyGridTable::AppendRow(const wxString& text, const wxString& image, const wxString& checkbox)
{
    data.push_back({ text, image, checkbox });
    numRows++;
}

bool MyGridTable::DeleteRows(size_t pos, size_t numRows)
{
    if (pos + numRows > data.size())
        return false;

    data.erase(data.begin() + pos, data.begin() + pos + numRows);
    this->numRows -= numRows;
    return true;
}

void MyGridTable::Clear()
{
    ClearData();
    numRows = 0;
}

void MyGridTable::SetData(const std::vector<std::vector<wxString>>& newData)
{
    data = newData;
    numRows = data.size();

    // Очищаем существующие данные в таблице
    grid->ClearGrid();

    // Обновляем отображение ячеек
    for (size_t row = 0; row < numRows; ++row) {
        for (size_t col = 0; col < numCols; ++col) {
            // Используем SetValue для обновления значения в ячейке
            grid->SetCellValue(row, col, data[row][col]);
        }
    }

    // Вызываем Refresh для обновления отображения
    grid->Refresh();
}

bool MyGridTable::AppendRows(size_t numRows)
{
    for (size_t i = 0; i < numRows; i++)
    {
        data.push_back({ wxEmptyString, wxEmptyString, wxEmptyString });
    }

    this->numRows += numRows;
    return true;
}

void MyGridTable::SortByName(bool isNameSorted)
{
    const int textColumn = 0;
    auto compareFunction = [&](const std::vector<wxString>& row1, const std::vector<wxString>& row2) {
        return isNameSorted ? row1[textColumn] < row2[textColumn] : row1[textColumn] > row2[textColumn];
    };
    std::sort(data.begin(), data.end(), compareFunction);
    grid->Refresh();
}

void MyGridTable::FilterByImage(bool isOnlyWithImage)
{
    const int imageColumn = 1; // Номер столбца "image"

        // Лямбда-функция для проверки условия
    auto condition = [&](const std::vector<wxString>& row) {
        return row.size() > imageColumn && (isOnlyWithImage ? (row[imageColumn] == "1") : true);
    };

    // Удаление элементов, не соответствующих условию
    data.erase(std::remove_if(data.begin(), data.end(), [&](const std::vector<wxString>& row) {
        return !condition(row);
        }), data.end());
}

const std::vector<std::vector<wxString>>& MyGridTable::GetData() const
{
    return data;
}
