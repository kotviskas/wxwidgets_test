#pragma once
#include <wx/string.h>
#include <wx/wx.h>
#include <wx/dataview.h>

class MusicNode;
WX_DEFINE_ARRAY_PTR(MusicNode*, MyMusicTreeModelNodePtrArray);

class MusicNode
{
public:
    MusicNode(MusicNode* parent,
        const wxString& branch)
    {
        m_parent = parent;
        m_title = branch;
        m_container = true;
    }

    ~MusicNode()
    {
        // free all our children nodes
        size_t count = m_children.GetCount();
        for (size_t i = 0; i < count; i++)
        {
            MusicNode* child = m_children[i];
            delete child;
        }
    }

    bool IsContainer() const
    {
        return m_container;
    }

    MusicNode* GetParent()
    {
        return m_parent;
    }
    MyMusicTreeModelNodePtrArray& GetChildren()
    {
        return m_children;
    }
    MusicNode* GetNthChild(unsigned int n)
    {
        return m_children.Item(n);
    }
    void Insert(MusicNode* child, unsigned int n)
    {
        m_children.Insert(child, n);
    }
    void Append(MusicNode* child)
    {
        m_children.Add(child);
    }
    unsigned int GetChildCount() const
    {
        return m_children.GetCount();
    }

public:     // public to avoid getters/setters
    wxString                m_title;
    wxString                m_artist;
    int                     m_year;
    wxString                m_quality;
    bool m_container;

private:
    MusicNode* m_parent;
    MyMusicTreeModelNodePtrArray   m_children;
};


class MusicModel: public wxDataViewModel
{
public:
    MusicModel();
    ~MusicModel()
    {
        delete m_root;
    }

    // helper method for wxLog
    wxString GetTitle(const wxDataViewItem& item) const;

    // helper methods to change the model
    void AddToClassical(const wxString& title);
    void Delete(const wxDataViewItem& item);

    // implementation of base class virtuals to define model
    virtual unsigned int GetColumnCount() const
    {
        return 6;
    }

    virtual void GetValue(wxVariant& variant,
        const wxDataViewItem& item, unsigned int col) const;
    virtual bool SetValue(const wxVariant& variant,
        const wxDataViewItem& item, unsigned int col);
    virtual wxDataViewItem GetParent(const wxDataViewItem& item) const;
    virtual bool IsContainer(const wxDataViewItem& item) const;
    virtual unsigned int GetChildren(const wxDataViewItem& parent,
        wxDataViewItemArray& array) const;

private:
    MusicNode* m_root;
    // pointers to some "special" nodes of the tree:
    MusicNode* m_pop;
    MusicNode* m_classical;
};

