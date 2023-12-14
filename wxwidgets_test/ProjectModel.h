#pragma once
#include <wx/wx.h>
#include <wx/dataview.h>

class ProjectNode {
public:
    ProjectNode(const wxString& title) : m_title(title) {}

    ~ProjectNode() {
        for (auto* child : m_children) {
            delete child;
        }
    }

    wxString GetTitle() const {
        return m_title;
    }

    void AddChild(ProjectNode* child) {
        m_children.push_back(child);
    }

    size_t GetChildCount() const {
        return m_children.size();
    }

    ProjectNode* GetChild(size_t index) const {
        if (index < m_children.size()) {
            return m_children[index];
        }
        return nullptr;
    }

    wxString m_title;
    const std::vector<ProjectNode*>& GetChildren() const {
        return m_children;
    }
private:
    std::vector<ProjectNode*> m_children;
};

class ProjectModel : public wxDataViewModel {
public:
    ProjectModel();

    ~ProjectModel() {
        delete m_root;
    }

    wxString GetTitle(const wxDataViewItem& item) const;
    void GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const;
    bool SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col);
    wxDataViewItem GetParent(const wxDataViewItem& item) const;
    bool IsContainer(const wxDataViewItem& item) const;
    unsigned int GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const;
    ProjectNode* m_root;
private:
    

    ProjectNode* FindParent(ProjectNode* current, ProjectNode* target) const {
        for (auto* child : current->GetChildren()) {
            if (child == target) {
                return current;
            }
            if (ProjectNode* parent = FindParent(child, target)) {
                return parent;
            }
        }
        return nullptr;
    }
};


