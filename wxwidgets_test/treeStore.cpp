#include "treeStore.h"

TreeStoreModel::TreeStoreModel()
{
    m_root = new TreeStoreNode(nullptr, "My Music");

    // setup pop music
    TreeStoreNode* pop = new TreeStoreNode(m_root, "Pop music");
    pop->Append(new TreeStoreNode(pop, "You are not alone"));
    pop->Append(new TreeStoreNode(pop, "Take a bow"));
    m_root->Append(pop);

    // setup classical music
    m_classical = new TreeStoreNode(m_root, "Classical music");
    m_root->Append(m_classical);
}

wxString TreeStoreModel::GetTitle(const wxDataViewItem& item) const
{
    TreeStoreNode* node = static_cast<TreeStoreNode*>(item.GetID());
    if (!node || !item.IsOk())
        return wxEmptyString;

    return node->m_title;
}


void TreeStoreModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const 
{
    wxASSERT(item.IsOk());

    TreeStoreNode* node = static_cast<TreeStoreNode*>(item.GetID());
    switch (col)
    {
    case 0:
        variant = node->m_title;
        break;
    default:
        wxLogError("GetValue: wrong column %d", col);
    }
}

bool TreeStoreModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col) 
{
    wxASSERT(item.IsOk());

    TreeStoreNode* node = static_cast<TreeStoreNode*>(item.GetID());
    switch (col)
    {
    case 0:
        node->m_title = variant.GetString();
        return true;
    default:
        wxLogError("SetValue: wrong column");
    }
    return false;
}

wxDataViewItem TreeStoreModel::GetParent(const wxDataViewItem& item) const 
{
    if (!item.IsOk())
        return wxDataViewItem(0);

    TreeStoreNode* node = static_cast<TreeStoreNode*>(item.GetID());
    if (node == m_root)
        return wxDataViewItem(0);

    TreeStoreNode* parent = node->GetParent();

    return wxDataViewItem(parent);
}

bool TreeStoreModel::IsContainer(const wxDataViewItem& item) const 
{
    if (!item.IsOk())
        return true;

    TreeStoreNode* node = static_cast<TreeStoreNode*>(item.GetID());
    return node->GetChildCount() > 0;
}

unsigned int TreeStoreModel::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const 
{
    TreeStoreNode* node = static_cast<TreeStoreNode*>(parent.GetID());
    if (!node)
    {
        array.Add(wxDataViewItem(m_root));
        return 1;
    }

    size_t count = node->GetChildCount();
    for (size_t i = 0; i < count; i++)
    {
        TreeStoreNode* child = node->GetChildren().Item(i);
        array.Add(wxDataViewItem(child));
    }

    return count;
}