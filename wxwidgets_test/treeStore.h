#pragma once
#include <wx/dataview.h>
#include <wx/wx.h>
#include <wx/dynarray.h>

class TreeStoreNode;
WX_DEFINE_ARRAY_PTR(TreeStoreNode*, TreeStoreNodePtrArray);

class TreeStoreNode : public wxDataViewTreeStoreNode
{
public:
    TreeStoreNode(TreeStoreNode* parent, const wxString& branch)
        : wxDataViewTreeStoreNode(parent, branch, wxNullBitmap), m_parent(parent), m_title(branch), m_container(true)
    {
    }

    ~TreeStoreNode()
    {
        // free all our children nodes
        size_t count = m_children.GetCount();
        for (size_t i = 0; i < count; i++)
        {
            TreeStoreNode* child = m_children[i];
            delete child;
        }
    }

    bool IsContainer() const
    {
        return m_container;
    }

    TreeStoreNode* GetParent()
    {
        return m_parent;
    }

    TreeStoreNodePtrArray& GetChildren()
    {
        return m_children;
    }

    TreeStoreNode* GetNthChild(unsigned int n)
    {
        if (n < m_children.GetCount())
        {
            return m_children.Item(n);
        }
        return nullptr;
    }

    void Insert(TreeStoreNode* child, unsigned int n)
    {
        m_children.Insert(child, n);
    }

    void Append(TreeStoreNode* child)
    {
        m_children.Add(child);
    }

    unsigned int GetChildCount() const
    {
        return m_children.GetCount();
    }

public:
    wxString                m_title;
    bool m_container;

private:
    TreeStoreNode* m_parent;
    TreeStoreNodePtrArray   m_children;
};

class TreeStoreModel : public wxDataViewTreeStore
{
public:
    TreeStoreModel();

    ~TreeStoreModel()
    {
        delete m_root;
    }

    wxDataViewItem GetRootItem() const
    {
        return wxDataViewItem(static_cast<void*>(m_root));
    }

    wxString GetTitle(const wxDataViewItem& item) const;

    virtual void GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const;

    virtual bool SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col);

    virtual wxDataViewItem GetParent(const wxDataViewItem& item) const;

    virtual bool IsContainer(const wxDataViewItem& item) const;

    virtual unsigned int GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const;

private:
    TreeStoreNode* m_root;
    TreeStoreNode* m_pop;
    TreeStoreNode* m_classical;
};