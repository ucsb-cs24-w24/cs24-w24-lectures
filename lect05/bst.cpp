//bst.cpp
#include <iostream>
using namespace std;

// bst is an Abstract Data Type
class bst{
 public:
    //initialization routine: constructor
    bst() { root = nullptr;}
    ~bst(){ clear(root);}
    // accessors or getter
    bool search(int value) const;
    int sum() const;
    void printInorder() const;
    int getHeight() const; // returns the height of the tree, maximum number of levels

    // mutators or setter
    void create_small_bst();
    void insert(int value);
    void clear();
    void erase(int value);

 private:
    struct Node{
        int data;
        Node* parent;
        Node* left;
        Node* right;
        Node (int d): data(d){
            parent = left = right = nullptr;
        }
    };
    Node* root;
    void printInorder(Node* r) const;
    int getHeight(Node* r) const;
    void clear(Node* r);
};
void bst::clear(Node* r){
    if(!r) return;
    clear(r->left);
    clear(r->right);
    delete r;
}
bool bst::search(int value) const{
    return false;
}
int bst::sum() const{
    return 42;
}
void bst::printInorder() const{
    printInorder(root);
    cout << endl;
}

int bst::getHeight() const{
    return getHeight(root);
} // returns the height of the tree, maximum number of levels

void bst::create_small_bst(){
    root = new Node(50);
    root->right = new Node(100);
    root->left = new Node(20);
    root->left->left = new Node(7);
    root->left->left->right = new Node(8);
    return;
}
void bst::insert(int value){
    return;
}
void bst::clear(){
    return;
}
void bst::erase(int value){
    return;
}
void bst::printInorder(Node* r) const{
    if(!r) return;
    printInorder(r->left);
    cout << r->data << " "; //visit the node!
    printInorder(r->right);
}

int bst::getHeight(Node* r) const{
    if(!r) return -1;
    //if(!r->left && !r->right) return 0;
    int hleft = getHeight(r->left);
    int hright = getHeight(r->right);
    return 1 + max(hleft, hright);
}
//Which traversal are we using
// A. Inorder B. Preorder C. Post order

// Leetcode: https://leetcode.com/problems/kth-smallest-element-in-a-bst
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void inorder(TreeNode* root, vector<int>& v){
    //     if(!root) return;
    //     inorder(root->left, v);
    //     v.push_back(root->val);
    //     // cout << root->val;
    //     inorder(root->right, v);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> v;
    //     inorder(root, v);
    //     return v[k - 1];
        
    // }
    int kthHelper(TreeNode* root, int k, int& rank){
        if(!root ) return -1;
        int left, right;
        if(root->left){
            left = kthHelper(root->left, k, rank);
        }
        rank++;
        if (k < rank) return left;
        if(k == rank) return root->val;
        right = kthHelper(root->right, k, rank);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int rank = 0;
        int result = kthHelper(root, k, rank);
        return result;
        
    }
};

int main() {
    bst b;
    b.create_small_bst();
    b.printInorder();
    cout << "Height = " << b.getHeight() << endl;
    return 0;
}