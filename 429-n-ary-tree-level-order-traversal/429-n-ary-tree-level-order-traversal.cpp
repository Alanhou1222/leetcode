/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root){
            q.push(root);
            while(!q.empty()){
                vector<int> level;
                int qSize = q.size();
                for(int i = 0; i < qSize; i++){
                    level.push_back(q.front()->val);
                    for(Node* &child:q.front()->children) q.push(child);
                    q.pop();
                }
                ans.push_back(level);
            }
        }
        
        return ans;
    }
};