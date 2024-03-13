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
    
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q, int& num_found) {
        if(!root) return nullptr;
        int num_left = 0, num_right = 0;
        TreeNode* left_lca, * right_lca;
        if(root->left) left_lca = LCA(root->left, p, q, num_left);
        num_found+=num_left;
        if(num_left == 2) return left_lca;

        if(root->right) right_lca = LCA(root->right, p, q, num_right);
        num_found+=num_right;
        if(num_right == 2) return right_lca;
        if(root->val == p->val || root->val == q->val){
            num_found++;
            if(num_left == 1 || num_right == 1) return root;
        }

        return root;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int num_found = 0;
        return LCA(root, p, q, num_found);
        
    }
    

    TreeNode* lowestCommonAncestor_0(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        bool found = false;
        DFS_FindPath(root, p, found, path_p);
        found = false;
        DFS_FindPath(root, q, found, path_q);
        TreeNode* result = path_p[0];
        int i = 1;
        while(i < min(path_p.size(), path_q.size())){
            if(path_p[i] == path_q[i]){
                result = path_p[i];
            }
            i++;
        }
        return result;
    }

    void DFS_FindPath(TreeNode* r, TreeNode* p, bool& found, vector<TreeNode*>& path){
        if(!r) return;
        path.push_back(r);
        if(r->val == p->val) {
            found = true;
            return;
        }
        //cout << r->val << " ";
        if(r->left && !found ) DFS_FindPath(r->left, p, found, path);
        if(r->right && !found ) DFS_FindPath(r->right, p, found, path);
        if(!found) path.pop_back();

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
    TreeNode* root = t1;

    TreeNode* result = ss.lowestCommonAncestor(root, root,root->left);
    assert(result->val == 1);
    cout << "PASSED TEST 0" << endl;

    root = t2;
    result =  ss.lowestCommonAncestor(root, root->left,root->right);
    assert(result->val == 3);
    cout << "PASSED TEST 1" << endl;
    result = ss.lowestCommonAncestor(root, root->left,root->left->right->right);
    assert(result->val == 5);
    cout << "PASSED TEST 2" << endl;
    result = ss.lowestCommonAncestor(root, root->left->left,root->left->right->right);
    assert(result->val == 5);
    cout << "PASSED TEST 3" << endl;

    return 0;
}
