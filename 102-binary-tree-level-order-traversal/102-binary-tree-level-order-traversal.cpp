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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> treeQueue;
        if(!root){
            return ans;
        }
        treeQueue.push(root);
        int len = 0;
        while(!treeQueue.empty()){
            len = treeQueue.size();
            vector<int> levelAns;
            while(len){
                TreeNode* temp = treeQueue.front();
                levelAns.push_back(temp->val);
                if(temp->left){
                    treeQueue.push(temp->left);
                }
                if(temp->right){
                    treeQueue.push(temp->right);
                }
                treeQueue.pop();
                len --;
            }
            ans.push_back(levelAns);
        }
        return ans;
    }
    
};