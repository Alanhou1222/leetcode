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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        TreeNode* curr;
        while(root){
            curr = root;
            if(curr->left){
                curr = root->left;
                while(curr->right){
                    curr = curr->right;
                }
                TreeNode* temp = root->left;
                curr->right = root;
                root->left = nullptr;
                root = temp;
            }
            else{
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};