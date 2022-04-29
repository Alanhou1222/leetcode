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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> treeStack;
        if(!root){
            return ans;
        }
        treeStack.push(root);
        while(!treeStack.empty()){
            TreeNode* temp = treeStack.top();
            if(temp){
                treeStack.push(nullptr);
                if(temp->right){
                    treeStack.push(temp->right);
                }
                if(temp->left){
                    treeStack.push(temp->left);
                }   
            }
            else{
                treeStack.pop();
                ans.push_back(treeStack.top()->val);
                treeStack.pop();
            }
        }
        return ans;
    }
};