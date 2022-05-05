/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pArr;
        vector<int> qArr;
        findPath(pArr, root, p, -1);
        findPath(qArr, root, q, -1);
        for(int i = 1; i < min(pArr.size(),qArr.size()); i++){
            if(pArr[i] == qArr[i]){
                if(pArr[i] ==0){
                    root = root->left;
                }
                else{
                    root = root->right;
                }
            }
            else{
                break;
            }
        }
        return root;
    }
    bool findPath(vector<int>& arr,TreeNode* &root, TreeNode* &find, int position){
        if(!root){
            return false;
        }
        arr.push_back(position);
        if(root->val == find->val){
            return true;
        }
        if(findPath(arr, root->left, find, 0)||findPath(arr, root->right, find, 1)){
            return true;
        }
        arr.pop_back();
        return false;
    }
};