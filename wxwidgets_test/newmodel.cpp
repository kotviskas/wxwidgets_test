#include "newmodel.h"

    // Конструктор
    MyDataModel::MyDataModel()
    {
        // Инициализация данных модели
        rootItem.text = "Root";
        rootItem.number = 0;

        childItems.push_back({ "Child 1", 10 });
        childItems.push_back({ "Child 2", 20 });
        childItems.push_back({ "Child 3", 30 });
    }
    unsigned int MyDataModel::GetColumnCount() const
    {
        return 2;
    }

    wxString MyDataModel::GetColumnType(unsigned int col) const
    {
        if (col == 0)
            return "string";
        else if (col == 1)
            return "long";
        else
            return wxEmptyString;
    }

    void MyDataModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const
    {
        if (!item.IsOk())
        {
            // Для корневого элемента
            if (col == 0)
                variant = rootItem.text;
            else if (col == 1)
                variant = rootItem.number;
        }
        else
        {
            // Для дочерних элементов
            ItemData& data = childItems[item.IsOk()];

            if (col == 0)
                variant = data.text;
            else if (col == 1)
                variant = data.number;
        }
    }

    bool MyDataModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col) 
    {
        if (!item.IsOk())
        {
            // Для корневого элемента
            if (col == 0)
                rootItem.text = variant.GetString();
            else if (col == 1)
                rootItem.number = variant.GetLong();
        }
        else
        {
            // Для дочерних элементов
            ItemData& data = childItems[item.IsOk()];

            if (col == 0)
                data.text = variant.GetString();
            else if (col == 1)
                data.number = variant.GetLong();
        }

        return true;
    }

    wxDataViewItem MyDataModel::GetParent(const wxDataViewItem& item) const
    {
        return wxDataViewItem(); // Корневой элемент
    }

    bool MyDataModel::IsContainer(const wxDataViewItem& item) const
    {
        return !item.IsOk(); // Корневой элемент является контейнером
    }

     unsigned int MyDataModel::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const
    {
        if (!parent.IsOk())
        {
            // Добавляем дочерние элементы для корневого элемента
            for (size_t i = 0; i < childItems.size(); ++i)
            {
                //wxDataViewItem childItem = AppendItem(wxDataViewItem(), childItems[i]);
                //array.Add(childItem);
                wxDataViewItem childItem(reinterpret_cast<void*>(static_cast<wxUIntPtr>(i)));
                array.Add(childItem);
            }

            return childItems.size();
        }

        return 0; // Дочерних элементов для дочерних элементов нет
    }