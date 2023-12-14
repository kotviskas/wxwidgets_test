#pragma once
#include <wx/wx.h>
#include <wx/dataview.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct TreeNodeJson {
    wxString name;
    std::vector<TreeNodeJson*> children;
    TreeNodeJson* parent;

    TreeNodeJson(const wxString& name, TreeNodeJson* p = nullptr) : name(name) {}

    ~TreeNodeJson() {
        for (auto* child : children) {
            delete child;
        }
    }
};

class TreeModelJson : public wxDataViewModel {
public:
    TreeModelJson(const json& jsonData);
    ~TreeModelJson() = default;

    void GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const override;
    bool SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col) override;

    wxString GetTitle(const wxDataViewItem& item) const;
    wxDataViewItem GetParent(const wxDataViewItem& item) const override;
    bool IsContainer(const wxDataViewItem& item) const override;
    unsigned int GetChildren(const wxDataViewItem& parent, wxDataViewItemArray& array) const override;

    unsigned int GetColumnCount() const override { return 1; }
    wxString GetColumnType(unsigned int col) const override { return "string"; }
    TreeNodeJson* ItemToNode(const wxDataViewItem& item) const;
private:
    TreeNodeJson m_root;
    TreeNodeJson* JsonToTreeNode(const json& jsonData, TreeNodeJson* parent);
};