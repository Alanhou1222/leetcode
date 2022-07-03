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
        stack<TreeNode*> ps;
        stack<TreeNode*> qs;
        find(ps, root, p);
        find(qs, root, q);
        while(ps.size() > qs.size()) ps.pop();
        while(ps.size() < qs.size()) qs.pop();
        while(!ps.empty()){
            if(ps.top() == qs.top()) return ps.top();
            ps.pop();
            qs.pop();
        }
        return nullptr;
    }
    
    void find(stack<TreeNode*> &s, TreeNode* root, TreeNode* target){
        s.push(root);
        if(root->val == target->val) return;
        if(root->val < target->val) find(s, root->right, target);
        else find(s, root->left, target);
    }
};