/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        unordered_map <Node*,Node*> oldToNew;
        Node* travel = head;
        while(travel){
            Node* temp = new Node(travel->val);
            oldToNew[travel] = temp;
            travel = travel->next;
        }
        oldToNew[nullptr] = nullptr;
        travel = head;
        Node* newHead = oldToNew[travel];
        while(travel){
            oldToNew[travel]->next = oldToNew[travel->next];
            oldToNew[travel]->random = oldToNew[travel->random];
            travel = travel->next;
        }
        return newHead;
    }
};