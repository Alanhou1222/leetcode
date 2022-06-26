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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pQueue;
        queue<TreeNode*> qQueue;
        pQueue.push(p);
        qQueue.push(q);
        while(!pQueue.empty()){
            if(!pQueue.front()&&!qQueue.front());
            else if(pQueue.front()&&qQueue.front()){
                pQueue.push(pQueue.front()->left);
                pQueue.push(pQueue.front()->right);
                qQueue.push(qQueue.front()->left);
                qQueue.push(qQueue.front()->right);
                if(pQueue.front()->val != qQueue.front()->val) return false;
            }
            else return false;
            pQueue.pop();
            qQueue.pop();
        }
        return true;
    }
};