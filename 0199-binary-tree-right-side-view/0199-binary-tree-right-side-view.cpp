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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int lastValue = 101;
            for(int i = 0; i < size; i++)
            {
                if(q.front() != nullptr) 
                {
                    lastValue = q.front()->val;
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(lastValue != 101) answer.push_back(lastValue);
        }
        return answer;
    }
};