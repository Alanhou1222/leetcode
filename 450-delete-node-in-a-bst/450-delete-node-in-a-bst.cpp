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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else{
            if(!root->left && !root->right) return nullptr;
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* replace = root->right;
            while(replace->left) replace = replace->left;
            root->val = replace->val;
            root->right = deleteNode(root->right, replace->val);
        }
        return root;
    }
};