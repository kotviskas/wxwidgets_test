#pragma once
#include <wx/wx.h>
#include <wx/dataview.h>

class TreeNode;
WX_DEFINE_ARRAY_PTR(TreeNode*, TreeNodePtrArray);

class TreeNode
{
public:
    TreeNode(TreeNode* parent, const wxString& name)
    {
        m_parent = parent;
        m_name = name;
    }

    ~TreeNode()
    {
        // Free all children nodes
        size_t count = m_children.GetCount();
        for (size_t i = 0; i < count; i++)
        {
            TreeNode* child = m_children[i];
            delete child;
        }
    }

    TreeNode* GetParent()
    {
        return m_parent;
    }

    const wxString& GetName() const
    {
        return m_name;
    }

    TreeNodePtrArray& GetChildren()
    {
        return m_children;
    }

    void AddChild(TreeNode* child)
    {
        m_children.Add(child);
    }

    unsigned int GetChildCount() const
    {
        return m_children.GetCount();
    }
    void Insert(TreeNode* child, unsigned int n)
    {
        m_children.Insert(child, n);
    }
public:
    wxString m_name;
private:
    TreeNode* m_parent;
    TreeNodePtrArray m_children;
};

class TreeModel : public wxDataViewModel
{
public:
    TreeModel();
    ~TreeModel()
    {
        delete m_root;
    }
    virtual void GetValue(wxVariant& variant,
        const wxDataViewItem& item, unsigned int col) const;
    virtual bool SetValue(const wxVariant& variant,
        const wxDataViewItem& item, unsigned int col);

    wxString GetTitle(const wxDataViewItem& item) const;

    virtual wxDataViewItem GetParent(const wxDataViewItem& item) const;

    virtual bool IsContainer(const wxDataViewItem& item) const;

    virtual unsigned int GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const;

    virtual unsigned int GetColumnCount() const {
        return 1; // Один столбец для названий
    }

    virtual wxString GetColumnType(unsigned int col) const {
        return "string";
    }

private:
    TreeNode* m_root;
};