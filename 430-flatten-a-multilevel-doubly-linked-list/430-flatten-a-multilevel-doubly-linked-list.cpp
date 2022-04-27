/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return nullptr;
        }
        if(!head->child){
            head->next = flatten(head->next);
        }
        else{
            Node* temp = head->next;
            Node* newNext = flatten(head->child);
            head->next = newNext;
            newNext->prev = head;
            head->child = nullptr;
            Node* travel = head->next;
            while(travel->next){
                travel = travel->next;
            }
            if(temp){
                travel->next = temp;
                temp->prev = travel;
            }
        }
        return head;
    }
    
};