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
    vector<TreeNode*> ans;
    unordered_map<string, short int> mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ans;
    }
    string helper(TreeNode* root){
        if(!root){
            return ",";
        }
        string str =  to_string(root->val)+",";
        str += helper(root->left);
        str += helper(root->right);
        mp[str]++;
        if(mp[str]==2){
            ans.push_back(root);
        }
        return str;
    }
};