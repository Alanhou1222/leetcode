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
    int sumNumbers(TreeNode* root, int number = 0) {
        int sum = 0;
        bool noChild = true;
        number = number * 10 + root->val;
        if(root->left != nullptr)
        {
            sum += sumNumbers(root->left, number);
            noChild = false;
        }
        if(root->right != nullptr)
        {
            sum += sumNumbers(root->right, number);
            noChild = false;
        }
        if(noChild)
        {
            sum += number;
        }
        return sum;
    }
};