//
// Created by Li,Yang(Duer04) on 2018/7/23.
//

#ifndef INC_1STPROGRAM_OFFER68_H
#define INC_1STPROGRAM_OFFER68_H

#include "../util/tree_util.h"
#include <list>

//bool GetNodePath(TreeNodeMulti* pRoot, TreeNodeMulti* pNode, std::list<TreeNodeMulti*>& path){
//    if (!pRoot) {
//        return false;
//    }
//    path.push_back(pRoot);
//    if (pRoot == pNode)
//        return true;
//    bool found = false;
//    auto iter = pRoot->children.begin();
//    while (!found && iter != pRoot->children.end())
//        found = GetNodePath(*iter++, pNode, path);
//    if (!found)
//        path.pop_back();
//    return found;
//}
//
//TreeNodeMulti* FindLatestAncients(std::list<TreeNodeMulti*>& path1, std::list<TreeNodeMulti*>& path2) {
//    if (path1.empty() || path2.empty())
//        return nullptr;
//    TreeNodeMulti* last_node = nullptr;
//    auto iter1 = path1.begin();
//    auto iter2 = path2.begin();
//    while (iter1 != path1.end() && iter2 != path2.end() && (*iter1 == *iter2)) {
//        last_node = *iter1;
//        ++iter1;
//        ++iter2;
//    }
//    return last_node;
//}
//
//TreeNodeMulti* FindLastCommonParents(TreeNodeMulti* pNode1, TreeNodeMulti* pNode2, TreeNodeMulti* pRoot) {
//    if (!pRoot || !pNode1 || !pNode2)
//        return nullptr;
//    std::list<TreeNodeMulti*> path1;
//    bool found = GetNodePath(pRoot, pNode1, path1);
//
//    std::list<TreeNodeMulti*> path2;
//    if (found)
//        found = GetNodePath(pRoot, pNode2, path2);
//    if (found) {
//        return FindLatestAncients(path1, path2);
//    }
//    else
//        return nullptr;
//}

bool GetNodePath(TreeNodeMulti* pRoot, TreeNodeMulti* pNode, std::list<TreeNodeMulti*>& path, bool print_debug=true) {
    if (pRoot == nullptr) {
        return false;
    }
    path.push_back(pRoot);
    if (print_debug) {
        std::cout << pRoot->value << std::endl;
    }

    if (pRoot == pNode) {
        return true;
    }
    bool found = false;
    auto iter = pRoot->children.begin();
    while (!found && iter != pRoot->children.end()) {
        found = GetNodePath(*iter++, pNode, path);
    }
    if (!found) {
        path.pop_back();
    }
    return found;
}

TreeNodeMulti* get_common_node(std::list<TreeNodeMulti*>& path1, std::list<TreeNodeMulti*>& path2, bool print_debug=true) {
    if (path1.empty() || path2.empty()) {
        return nullptr;
    }
    auto iter1 = path1.begin();
    auto iter2 = path2.begin();
    if (print_debug) {
        std::cout << (*iter1)->value << " " << (*iter2)->value << std::endl;
    }
    TreeNodeMulti* last_node = nullptr;
    while (iter1 != path1.end() && iter2 != path2.end() && (*iter1)->value == (*iter2)->value) {
        last_node = *iter1;
        ++iter1;
        ++iter2;
        if (print_debug) {
            std::cout << last_node->value << std::endl;
        }
    }
    return last_node;
}

TreeNodeMulti* FindLastCommonParents(TreeNodeMulti* root, TreeNodeMulti* node1, TreeNodeMulti* node2, bool print_debug=true) {
    if (!root || !node1 || !node2) {
        return nullptr;
    }
    std::list<TreeNodeMulti*> path1;
    std::cout << "get path1" << std::endl;
    bool found = GetNodePath(root, node1, path1);
    if (print_debug) {
        if (found) {
            std::cout << "path1" << std::endl;
            for (auto iter = path1.begin(); iter != path1.end(); ++iter) {
                std::cout << (*iter)->value << std::endl;
            }
        }
    }
    std::list<TreeNodeMulti*> path2;
    if (found) {
        std::cout << "get path2" << std::endl;
        found = GetNodePath(root, node2, path2);
        if (print_debug) {
            if (found) {
                std::cout << "path2" << std::endl;
                for (auto iter = path2.begin(); iter != path2.end(); ++iter) {
                    std::cout << (*iter)->value << std::endl;
                }
            }
        }
    }
    if (found) {
        TreeNodeMulti* node = get_common_node(path1, path2);
        return node;
    }
    return nullptr;
}

void test_FindLastCommonParents() {
    auto * node1 = new TreeNodeMulti();
    node1->value = 1;

    auto * node2 = new TreeNodeMulti();
    node2->value = 2;

    auto * node3 = new TreeNodeMulti();
    node3->value = 3;

    auto * node4 = new TreeNodeMulti();
    node4->value = 4;

    auto * node5 = new TreeNodeMulti();
    node5->value = 5;

    auto * node6 = new TreeNodeMulti();
    node6->value = 6;

    auto * node7 = new TreeNodeMulti();
    node7->value = 7;


    std::vector<TreeNodeMulti*> node1_children = {node2, node3};
    std::vector<TreeNodeMulti*> node2_children = {node4, node5};
    std::vector<TreeNodeMulti*> node3_children = {node6, node7};

    connect_tree_node(node1, node1_children);
    connect_tree_node(node2, node2_children);
    connect_tree_node(node3, node3_children);

    std::cout << FindLastCommonParents(node1, node4, node6)->value << std::endl;
}
#endif //INC_1STPROGRAM_OFFER68_H
