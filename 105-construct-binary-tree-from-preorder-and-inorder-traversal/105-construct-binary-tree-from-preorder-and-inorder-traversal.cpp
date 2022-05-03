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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int, int> inorderMap;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inorderMap[inorder[i]] = i;
        }
        TreeNode* root = helper(inorder,preorder,0,n-1,inorderMap);
        return root;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int startIndex, int endIndex, unordered_map<int, int> &inorderMap) {     
        if(preorder.empty()||startIndex > endIndex){
            return nullptr;
        }
        int rootVal = preorder.front();
        preorder.erase(preorder.begin());
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(inorder, preorder, startIndex, inorderMap[rootVal]-1, inorderMap);
        root->right = helper(inorder, preorder, inorderMap[rootVal]+1, endIndex, inorderMap);
        
        return root;
    }
};