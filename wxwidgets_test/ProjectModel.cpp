#include "ProjectModel.h"

ProjectModel::ProjectModel() {
    m_root = new ProjectNode("Project");
}

wxString ProjectModel::GetTitle(const wxDataViewItem& item) const {
    ProjectNode* node = static_cast<ProjectNode*>(item.GetID());
    if (!node) {
        return wxEmptyString;
    }

    return node->GetTitle();
}

void ProjectModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const {
    wxASSERT(item.IsOk());

    ProjectNode* node = static_cast<ProjectNode*>(item.GetID());
    switch (col) {
    case 0:
        variant = node->GetTitle();
        break;
    default:
        wxLogError("MusicModel::GetValue: wrong column %d", col);
    }
}

bool ProjectModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col) {
    wxASSERT(item.IsOk());

    ProjectNode* node = static_cast<ProjectNode*>(item.GetID());
    switch (col) {
    case 0:
        node->m_title = variant.GetString();
        return true;
    default:
        wxLogError("MusicModel::SetValue: wrong column");
    }
    return false;
}

wxDataViewItem ProjectModel::GetParent(const wxDataViewItem& item) const {
    if (!item.IsOk()) {
        return wxDataViewItem(0);
    }

    ProjectNode* node = static_cast<ProjectNode*>(item.GetID());
    if (node == m_root) {
        return wxDataViewItem(0);
    }

    // Find parent in children
    for (auto* child : m_root->GetChildren()) {
        if (child == node) {
            return wxDataViewItem(static_cast<void*>(m_root));
        }
        if (ProjectNode* parent = FindParent(child, node)) {
            return wxDataViewItem(static_cast<void*>(parent));
        }
    }

    return wxDataViewItem(0);
}

bool ProjectModel::IsContainer(const wxDataViewItem& item) const {
    if (!item.IsOk()) {
        return true;
    }

    ProjectNode* node = static_cast<ProjectNode*>(item.GetID());
    return node->GetChildCount() > 0;
}

unsigned int ProjectModel::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const {
    ProjectNode* parentNode = static_cast<ProjectNode*>(parent.GetID());
    if (!parentNode) {
        array.Add(wxDataViewItem(static_cast<void*>(m_root)));
        return 1;
    }

    size_t count = parentNode->GetChildCount();
    for (size_t i = 0; i < count; i++) {
        ProjectNode* child = parentNode->GetChild(i);
        array.Add(wxDataViewItem(static_cast<void*>(child)));
    }

    return count;
}
