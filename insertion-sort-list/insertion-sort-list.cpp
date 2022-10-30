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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* prev = head;
        ListNode* next = head->next;
        while(next){
            if(head->val > next->val){
                prev->next = next->next;
                next->next = head;
                head = next;
                next = prev->next;
                continue;
            }
            ListNode* temp = head;
            while(temp->next != next && temp->next->val < next->val){
                temp = temp->next;
            }
            if(temp->next == next){
                prev = next;
                next = next->next;
            }
            else{
                prev->next = next->next;
                next->next = temp->next;
                temp->next = next;
                next = prev->next;
            }
        }
        return head;
    }
};