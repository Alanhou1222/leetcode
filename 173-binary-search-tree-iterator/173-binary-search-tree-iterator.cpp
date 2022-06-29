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
class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* cur = nullptr;
public:
    BSTIterator(TreeNode* root) {
        s.push(root);
        while(root->left){
            s.push(root->left);
            root = root->left;
        }
    }
    
    int next() {
        cur = s.top();
        TreeNode* temp = s.top()->right;
        s.pop();
        if(temp){
            s.push(temp);
            while(temp->left){
            s.push(temp->left);
            temp = temp->left;
            }
        }
        return cur->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */