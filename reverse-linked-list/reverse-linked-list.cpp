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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* oldHead = head;
        while(oldHead->next){
            ListNode* temp = oldHead->next;
            oldHead->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};