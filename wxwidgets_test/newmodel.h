#pragma once
#include <wx/wx.h>
#include <wx/dataview.h>

class MyDataModel : public wxDataViewModel
{
public:
    // Заглушка для данных
    struct ItemData
    {
        wxString text = "11223";
        long number = 111;
    };

    mutable std::vector<ItemData> childItems;
    ItemData rootItem;
    // Конструктор
    MyDataModel();
    ~MyDataModel() {

    }
    
    virtual unsigned int GetColumnCount() const;
    
    virtual wxString GetColumnType(unsigned int col) const;

    virtual void GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const;

    virtual bool SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col);

    virtual wxDataViewItem GetParent(const wxDataViewItem& item) const;

    virtual bool IsContainer(const wxDataViewItem& item) const;

    virtual unsigned int GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const;
};
