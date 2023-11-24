#include "treeModel.h"

TreeModel::TreeModel()
{
    m_root = new TreeNode(nullptr, "My Music");

    // Setup pop music
    TreeNode* pop = new TreeNode(m_root, "Pop music");
    pop->AddChild(new TreeNode(pop, "You are not alone"));
    pop->AddChild(new TreeNode(pop, "Take a bow"));
    m_root->AddChild(pop);

    // Setup classical music
    m_root->AddChild(new TreeNode(m_root, "Classical music"));
}

void TreeModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const
{
    wxASSERT(item.IsOk());

    TreeNode* node = (TreeNode*)item.GetID();
    switch (col)
    {
    case 0:
        variant = node->m_name;
        break;
    default:
        wxLogError("GetValue: wrong column %d", col);
    }
}

bool TreeModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col)
{
    wxASSERT(item.IsOk());

    TreeNode* node = (TreeNode*)item.GetID();
    switch (col)
    {
    case 0:
        node->m_name = variant.GetString();
        return true;
    default:
        wxLogError("MyMusicTreeModel::SetValue: wrong column");
    }
    return false;
}

wxString TreeModel::GetTitle(const wxDataViewItem& item) const
{
    TreeNode* node = static_cast<TreeNode*>(item.GetID());
    if (!node || !item.IsOk())
        return wxEmptyString;

    return node->GetName();
}

wxDataViewItem TreeModel::GetParent(const wxDataViewItem& item) const
{
    if (!item.IsOk())
        return wxDataViewItem(0);

    TreeNode* node = static_cast<TreeNode*>(item.GetID());
    if (node == m_root)
        return wxDataViewItem(0);

    TreeNode* parent = node->GetParent();

    return wxDataViewItem(parent);
}

bool TreeModel::IsContainer(const wxDataViewItem& item) const
{
    if (!item.IsOk())
        return true;

    TreeNode* node = static_cast<TreeNode*>(item.GetID());
    return node->GetChildCount() > 0;
}

unsigned int TreeModel::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const
{
    TreeNode* node = static_cast<TreeNode*>(parent.GetID());
    if (!node)
    {
        array.Add(wxDataViewItem(m_root));
        return 1;
    }

    size_t count = node->GetChildCount();
    for (size_t i = 0; i < count; i++)
    {
        TreeNode* child = node->GetChildren().Item(i);
        array.Add(wxDataViewItem(child));
    }

    return count;
}