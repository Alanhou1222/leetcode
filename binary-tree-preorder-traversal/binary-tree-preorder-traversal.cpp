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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        TreeNode* temp;
        while(!treeStack.empty()){
            temp = treeStack.top();
            treeStack.pop();
            ans.push_back(temp->val);
            if(temp->right){
                treeStack.push(temp->right);
            }
            if(temp->left){
                treeStack.push(temp->left);
            }
        }
        return ans;
    }
};