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
    vector<TreeNode*> generateTrees(int n) {
        return uniqueTreesGenerator(1,n);
    }
    vector<TreeNode*> uniqueTreesGenerator(int left, int right) {
        vector<TreeNode*> uniqueTrees;
        if(left>right){
            uniqueTrees.push_back(nullptr);
            return uniqueTrees;
        }
        if(left==right){
            uniqueTrees.push_back(new TreeNode(left));
            return uniqueTrees;
        }
        for(int i = left; i <= right; i++){
            vector<TreeNode*> leftSubTrees = uniqueTreesGenerator(left, i-1);
            vector<TreeNode*> rightSubTrees = uniqueTreesGenerator(i+1, right);
            for(TreeNode* leftNode:leftSubTrees){
                for(TreeNode* rightNode:rightSubTrees){
                    uniqueTrees.push_back(new TreeNode(i,leftNode,rightNode));
                }
            }
        }
        return uniqueTrees;
    }
    
};