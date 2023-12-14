#include "models.h"

MusicModel1::MusicModel1()
{
    m_root = new MusicNode1(NULL, "My Music");
}

wxString MusicModel1::GetTitle(const wxDataViewItem& item) const
{
    MusicNode1* node = (MusicNode1*)item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_title;
}

void MusicModel1::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const
{
    wxASSERT(item.IsOk());

    MusicNode1* node = (MusicNode1*)item.GetID();
    switch (col)
    {
    case 0:
        variant = node->m_title;
        break;
    default:
        wxLogError("MyMusicTreeModel::GetValue: wrong column %d", col);
    }
}

bool MusicModel1::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col)
{
    wxASSERT(item.IsOk());

    MusicNode1* node = (MusicNode1*)item.GetID();
    switch (col)
    {
    case 0:
        node->m_title = variant.GetString();
        return true;
    default:
        wxLogError("MyMusicTreeModel::SetValue: wrong column");
    }
    return false;
}

wxDataViewItem MusicModel1::GetParent(const wxDataViewItem& item) const
{
    // the invisible root node has no parent
    if (!item.IsOk())
        return wxDataViewItem(0);

    MusicNode1* node = (MusicNode1*)item.GetID();

    // "MyMusic" also has no parent
    if (node == m_root)
        return wxDataViewItem(0);

    return wxDataViewItem((void*)node->GetParent());
}

bool MusicModel1::IsContainer(const wxDataViewItem& item) const
{
    // the invisble root node can have children
    // (in our model always "MyMusic")
    if (!item.IsOk())
        return true;

    MusicNode1* node = (MusicNode1*)item.GetID();
    return node->GetChildCount() > 0;
}

unsigned int MusicModel1::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const
{
    MusicNode1* node = (MusicNode1*)parent.GetID();
    if (!node)
    {
        array.Add(wxDataViewItem((void*)m_root));
        return 1;
    }
    unsigned int count = node->GetChildCount();
    for (unsigned int pos = 0; pos < count; pos++)
    {
        MusicNode1* child = node->GetChildren().Item(pos);
        array.Add(wxDataViewItem((void*)child));
    }
    return count;
}
