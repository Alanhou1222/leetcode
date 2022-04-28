/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        int length = 1;
        ListNode* travel = head;
        ListNode* last = head;
        ListNode* newHead = head;
        while(last->next){
            length++;
            last = last->next;
        }
        k = k%length;
        k = length-k;
        travel = head;
        if(k>0){
            while(k>1){
                travel = travel->next;
                k--;
            }
            last->next = head;
            newHead = travel->next;
            travel->next = nullptr;
        }
        return newHead;
        
        
    }
};