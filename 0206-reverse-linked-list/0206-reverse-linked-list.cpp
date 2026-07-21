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
    ListNode* reverseList(ListNode* head, ListNode* parent= nullptr) {
        if(head==nullptr){
            //this happens at the very end
            return parent;
        }
        auto newHead=reverseList(head->next,head);
        head->next=parent;
        return newHead;
    }
};