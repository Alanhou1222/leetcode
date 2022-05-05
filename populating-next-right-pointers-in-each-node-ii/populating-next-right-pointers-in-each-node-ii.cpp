/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* temp = root;
        while(temp){
            bool findStart = false;
            Node* nextStart = nullptr;
            Node* left = temp->left;
            Node* right = temp->right;
            if(!findStart&&left){
                nextStart = left;
                findStart = true;
            }
            while(temp){
                if(left&&right){
                    left->next = right;
                    left = right;
                    move(right, temp);
                }
                else if(!left){
                    left = right;
                    move(right, temp);
                }
                else{
                    move(right, temp);
                }
                if(!findStart&&left){
                    nextStart = left;
                    findStart = true;
                }
                if(right == nullptr){
                    break;
                }
            }
            temp = nextStart;
        }
        return root;
    }
    void move(Node* &right, Node* &temp){
        if(right == temp->left){
            if(temp->right){
                right = temp->right;
                return;
            }
        }
        while(temp->next){
            temp = temp->next;
            if(temp->left){
                right = temp->left;
                return;
            }
            if(temp->right){
                right = temp->right;
                return;
            }
        }
        right = nullptr;
        return;
    }
};