#include "treeModelJson.h"

/*TreeModelJson::TreeModelJson(const json& jsonData) : m_root("My Music") {
    TreeNodeJson* pop = JsonToTreeNode(jsonData, &m_root);
    m_root.children.push_back(pop);
}

void TreeModelJson::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const {
    wxASSERT(item.IsOk());

    const TreeNodeJson* node = static_cast<const TreeNodeJson*>(item.GetID());
    if (node) {
        variant = node->name;
    }
    else {
        wxLogError("GetValue: Invalid item");
    }
}

bool TreeModelJson::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col) {
    wxASSERT(item.IsOk());

    TreeNodeJson* node = static_cast<TreeNodeJson*>(item.GetID());
    if (node) {
        node->name = variant.GetString();
        return true;
    }
    else {
        wxLogError("SetValue: Invalid item");
        return false;
    }
}

wxString TreeModelJson::GetTitle(const wxDataViewItem& item) const {
    const TreeNodeJson* node = static_cast<const TreeNodeJson*>(item.GetID());
    if (node && item.IsOk()) {
        return node->name;
    }
    else {
        return wxEmptyString;
    }
}

wxDataViewItem TreeModelJson::GetParent(const wxDataViewItem& item) const {
    TreeNodeJson* node = static_cast<TreeNodeJson*>(item.GetID());
    if (node && node != &m_root) {
        // Используем указатель на родителя
        return wxDataViewItem(static_cast<void*>(node->parent));
    }

    return wxDataViewItem(0);
}

bool TreeModelJson::IsContainer(const wxDataViewItem& item) const {
    const TreeNodeJson* node = static_cast<const TreeNodeJson*>(item.GetID());
    return node && item.IsOk() && !node->children.empty();
}

unsigned int TreeModelJson::GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const {
    TreeNodeJson* parentNode = static_cast<TreeNodeJson*>(parent.GetID());
    if (!parentNode) {
        // Если parent не указан, добавляем корневой узел
        array.Add(wxDataViewItem(m_root));
        return 1;
    }

    size_t count = parentNode->children.size();
    for (size_t i = 0; i < count; i++) {
        TreeNodeJson* child = parentNode->children[i];
        array.Add(wxDataViewItem(static_cast<void*>(child)));
    }

    return count;
}

TreeNodeJson* TreeModelJson::JsonToTreeNode(const json& jsonData, TreeNodeJson* parent) {
    auto node = new TreeNodeJson(jsonData["name"].get<std::string>());

    const auto& children = jsonData.value("children", json::array());
    for (const auto& childData : children) {
        TreeNodeJson* child = JsonToTreeNode(childData, node);
        node->children.push_back(child);
    }

    return node;
}

TreeNodeJson* TreeModelJson::ItemToNode(const wxDataViewItem& item) const {
    if (!item.IsOk()) {
        return nullptr;
    }
    return static_cast<TreeNodeJson*>(item.GetID());
}*/