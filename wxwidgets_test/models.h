#pragma once
#include <wx/string.h>
#include <wx/wx.h>
#include <wx/dataview.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class MusicNode1;
WX_DEFINE_ARRAY_PTR(MusicNode1*, MyMusicTreeModelNodePtrArray);

class MusicNode1
{
public:
    MusicNode1(MusicNode1* parent,
        const wxString& branch)
    {
        m_parent = parent;
        m_title = branch;
    }

    ~MusicNode1()
    {
        // free all our children nodes
        size_t count = m_children.GetCount();
        for (size_t i = 0; i < count; i++)
        {
            MusicNode1* child = m_children[i];
            delete child;
        }
    }

    MusicNode1* GetParent()
    {
        return m_parent;
    }
    MyMusicTreeModelNodePtrArray& GetChildren()
    {
        return m_children;
    }
    MusicNode1* GetNthChild(unsigned int n)
    {
        return m_children.Item(n);
    }
    void Insert(MusicNode1* child, unsigned int n)
    {
        m_children.Insert(child, n);
    }
    void Append(MusicNode1* child)
    {
        m_children.Add(child);
    }
    unsigned int GetChildCount() const
    {
        return m_children.GetCount();
    }

public:     // public to avoid getters/setters
    wxString                m_title;
private:
    MusicNode1* m_parent;
    MyMusicTreeModelNodePtrArray   m_children;
};


class MusicModel1: public wxDataViewModel
{
public:
    MusicModel1();
    ~MusicModel1()
    {
        delete m_root;
    }

    // helper method for wxLog
    wxString GetTitle(const wxDataViewItem& item) const;

    // implementation of base class virtuals to define model
    virtual unsigned int GetColumnCount() const
    {
        return 1;
    }
    virtual wxString GetColumnType(unsigned int col) const {
        return "string";
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
    MusicNode1* m_root;
};

