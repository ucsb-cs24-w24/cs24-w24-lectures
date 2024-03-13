// lca.cpp
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void preorder(TreeNode *r){
        if(!r) return;
        cout << r -> val << " ";
        if(r->left) preorder(r->left);
        if(r->right) preorder(r->right);
    }

    TreeNode* make_tree_1(){
        // Input: root = [1,2], p = 1, q = 2
        // Output: 1
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        return root;
        
    }

    TreeNode* make_tree_2(){
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    // Output: 3
    // Explanation: The LCA of nodes 5 and 1 is 3.
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        TreeNode *p = root->left;
        p->left =  new TreeNode(6);
        p->right = new TreeNode(2);
        p = root->right;
        p->left =  new TreeNode(0);
        p->right = new TreeNode(8);
        p = root->left->right;
        p->left =  new TreeNode(7);
        p->right = new TreeNode(4);
        return root;
    }

    void exploreBFS(TreeNode* r){
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty()){
            TreeNode* fr = q.front();
            cout << fr->val << " ";
            q.pop();
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        cout << endl;

    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return root;  
    }



    void DFS_FindPath(TreeNode* r, TreeNode* p, bool& found, vector<TreeNode*>& path){

    }

    void exploreDFS(TreeNode* r){
        if(!r) return;
        cout << r->val << " ";
        if(r->left) exploreDFS(r->left);
        if(r->right) exploreDFS(r->right);
    }

};



int main(int argc, char const *argv[])
{
    Solution ss;
    TreeNode* t1 = ss.make_tree_1();
    TreeNode* t2 = ss.make_tree_2();
    ss.exploreBFS(t2);
    bool found = false;
    vector<TreeNode*> path;
    cout << "Find " << t2->right->left->val << endl;
    ss.DFS_FindPath(t2, t2->right->left, found, path);
    for(auto e:path){
        cout << e->val << " ";
    }
    cout << endl;
    // TreeNode* root = t1;

    // TreeNode* result = ss.lowestCommonAncestor(root, root,root->left);
    // assert(result->val == 1);
    // cout << "PASSED TEST 0" << endl;

    // root = t2;
    // result =  ss.lowestCommonAncestor(root, root->left,root->right);
    // assert(result->val == 3);
    // cout << "PASSED TEST 1" << endl;
    // result = ss.lowestCommonAncestor(root, root->left,root->left->right->right);
    // assert(result->val == 5);
    // cout << "PASSED TEST 2" << endl;
    // result = ss.lowestCommonAncestor(root, root->left->left,root->left->right->right);
    // assert(result->val == 5);
    // cout << "PASSED TEST 3" << endl;

    return 0;
}
