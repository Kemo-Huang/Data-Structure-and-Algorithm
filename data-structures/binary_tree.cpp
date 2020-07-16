#include <iostream>

#include "utils.h"

using namespace std;

class ListNode {
   public:
    string val;
    ListNode* next;
    ListNode(string s) {
        val = s;
        next = nullptr;
    }
};

class BinTreeNode {
   public:
    string val;
    BinTreeNode* left = nullptr;
    BinTreeNode* right = nullptr;
    BinTreeNode(string val);
};

BinTreeNode::BinTreeNode(string val) { this->val = val; }

class BinTree {
   private:
    BinTreeNode* root;
    ListNode* ln;
    BinTreeNode* r_deserialize();
    string r_serialize(BinTreeNode* node, string str);

   public:
    BinTree(string data);
    ~BinTree();
    string serialize();
    int get_num_leaves();
    int get_num_nodes_with_degree(int degree);
};
/**
 * @tparam data  string data
 */
BinTree::BinTree(string data) {
    vector<string> v_data = split_str(data, ',');
    ln = new ListNode(v_data[0]);
    ListNode* tmp = ln;
    for (int i = 1; i< v_data.size(); ++i){
        tmp->next = new ListNode(v_data[i]);
        tmp = tmp->next;
    }
    tmp = ln;
    this->root = r_deserialize();
    while (tmp != nullptr) {
        ListNode* next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

BinTreeNode* BinTree::r_deserialize() {
    if (ln == nullptr) {
        return nullptr;
    }
    if (ln->val == "null") {
        ln = ln->next;
        return nullptr;
    }
    BinTreeNode* node = new BinTreeNode(ln->val);
    ln = ln->next;
    node->left = r_deserialize();
    node->right = r_deserialize();
    return node;
}

string BinTree::r_serialize(BinTreeNode* node, string str) {
    if (node == nullptr) {
        str += "null,";
    } else {
        str += node->val + ",";
        str = r_serialize(node->left, str);
        str = r_serialize(node->right, str);
    }
    return str;
}

void r_delete_node(BinTreeNode* node) {
    if (node) {
        r_delete_node(node->left);
        r_delete_node(node->right);
        delete node;
        node = nullptr;
    }
}

BinTree::~BinTree() { r_delete_node(root); }

string BinTree::serialize() { return r_serialize(root, ""); }

int BinTree::get_num_leaves() { return get_num_nodes_with_degree(0); }

// TODO
int BinTree::get_num_nodes_with_degree(int degree) { return 0; }
