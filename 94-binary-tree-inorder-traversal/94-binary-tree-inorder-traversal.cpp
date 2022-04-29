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
        stack<pair<TreeNode*,bool>> treeStack;
        if(!root->left){
            treeStack.push({root,true});
        }
        else{
            treeStack.push({root,true});
            treeStack.push({root->left,false});
        }
        while(!treeStack.empty()){
            if(!treeStack.top().second&&treeStack.top().first->left){
                treeStack.top().second = true;
                treeStack.push({treeStack.top().first->left,false});
                continue;
            }
            pair<TreeNode*,bool> temp = treeStack.top();
            treeStack.pop();
            ans.push_back(temp.first->val);
            if(temp.first->right){
                treeStack.push({temp.first->right,false});
            }
        }
        return ans;
    }
};