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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we will use an advanced node.
        // ListNode sentinelHead;
        // sentinelHead.next=head;
        auto fast = head;
        auto slow = head;
        ListNode* prev=nullptr;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(!prev){
            // we are removing the head.
            // slow is at the head.
            return slow->next; 
        }
        prev->next = slow->next;
        return head;
    }
};