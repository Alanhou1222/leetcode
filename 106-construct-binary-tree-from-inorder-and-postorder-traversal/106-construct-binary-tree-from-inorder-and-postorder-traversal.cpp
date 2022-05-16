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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inorderMap[inorder[i]] = i;
        }
        TreeNode* root = helper(inorder,postorder,0,n-1,inorderMap);
        return root;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int startIndex, int endIndex, unordered_map<int, int> &inorderMap) {     
        if(postorder.empty()||startIndex > endIndex){
            return nullptr;
        }
        int rootVal = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(rootVal);
        root->right = helper(inorder, postorder, inorderMap[rootVal]+1, endIndex, inorderMap);
        root->left = helper(inorder, postorder, startIndex, inorderMap[rootVal]-1, inorderMap);
        return root;
    }
    
};