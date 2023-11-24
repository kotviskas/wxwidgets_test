#include "models.h"

MusicModel::MusicModel()
{
    m_root = new MusicNode(NULL, "My Music");

    // setup pop music
    m_pop = new MusicNode(m_root, "Pop music");
    m_pop->Append(
        new MusicNode(m_pop, "You are not alone"));
    m_pop->Append(
        new MusicNode(m_pop, "Take a bow"));
    m_root->Append(m_pop);

    // setup classical music
    m_classical = new MusicNode(m_root, "Classical music");
    m_root->Append(m_classical);
}

wxString MusicModel::GetTitle(const wxDataViewItem& item) const
{
    MusicNode* node = (MusicNode*)item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return wxEmptyString;

    return node->m_title;
}

void MusicModel::AddToClassical(const wxString& title)
{
    if (!m_classical)
    {
        wxASSERT(m_root);

        // it was removed: restore it
        m_classical = new MusicNode(m_root, "Classical music");
        m_root->Append(m_classical);

        // notify control
        wxDataViewItem child((void*)m_classical);
        wxDataViewItem parent((void*)m_root);
        ItemAdded(parent, child);
    }

    // add to the classical music node a new node:
    MusicNode* child_node =
        new MusicNode(m_classical, title);
    m_classical->Append(child_node);

    // notify control
    wxDataViewItem child((void*)child_node);
    wxDataViewItem parent((void*)m_classical);
    ItemAdded(parent, child);
}

void MusicModel::Delete(const wxDataViewItem& item)
{
    MusicNode* node = (MusicNode*)item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return;

    wxDataViewItem parent(node->GetParent());
    if (!parent.IsOk())
    {
        wxASSERT(node == m_root);

        // don't make the control completely empty:
        wxLogError("Cannot remove the root item!");
        return;
    }

    // is the node one of those we keep stored in special pointers?
    if (node == m_pop)
        m_pop = NULL;
    else if (node == m_classical)
        m_classical = NULL;

    // first remove the node from the parent's array of children;
    // NOTE: MyMusicTreeModelNodePtrArray is only an array of _pointers_
    //       thus removing the node from it doesn't result in freeing it
    node->GetParent()->GetChildren().Remove(node);
    // free the node
    delete node;
    // notify control
    ItemDeleted(parent, item);
}

void MusicModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const
{
    wxASSERT(item.IsOk());

    MusicNode* node = (MusicNode*)item.GetID();
    switch (col)
    {
    case 0:
        variant = node->m_title;
        break;
    default:
        wxLogError("MyMusicTreeModel::GetValue: wrong column %d", col);
    }
}

bool MusicModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col)
{
    wxASSERT(item.IsOk());

    MusicNode* node = (MusicNode*)item.GetID();
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

wxDataViewItem MusicModel::GetParent(const wxDataViewItem& item) const
{
    // the invisible root node has no parent
    if (!item.IsOk())
        return wxDataViewItem(0);

    MusicNode* node = (MusicNode*)item.GetID();

    // "MyMusic" also has no parent
    if (node == m_root)
        return wxDataViewItem(0);

    return wxDataViewItem((void*)node->GetParent());
}

bool MusicModel::IsContainer(const wxDataViewItem& item) const
{
    // the invisble root node can have children
    // (in our model always "MyMusic")
    if (!item.IsOk())
        return true;

    MusicNode* node = (MusicNode*)item.GetID();
    return node->IsContainer();
}

unsigned int MusicModel::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const
{
    MusicNode* node = (MusicNode*)parent.GetID();
    if (!node)
    {
        array.Add(wxDataViewItem((void*)m_root));
        return 1;
    }
    if (node == m_classical)
    {
        MusicModel* model = (MusicModel*)(const MusicModel*)this;
    }
    if (node->GetChildCount() == 0)
    {
        return 0;
    }
    unsigned int count = node->GetChildren().GetCount();
    for (unsigned int pos = 0; pos < count; pos++)
    {
        MusicNode* child = node->GetChildren().Item(pos);
        array.Add(wxDataViewItem((void*)child));
    }
    return count;
}
