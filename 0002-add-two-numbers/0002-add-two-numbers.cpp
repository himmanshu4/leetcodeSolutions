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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto sumHead = new ListNode();
        auto sumOrigin = sumHead;
        sumHead->val = (l1->val + l2->val) % 10;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 && l2) {
            sumHead->next = new ListNode();
            sumHead = sumHead->next;
            sumHead->val = (carry + l1->val + l2->val) % 10;
            carry = (carry + l1->val + l2->val) / 10;
            l1=l1->next;
            l2=l2->next;
        }
        auto lRem = l1 ? l1 : l2;
        while (lRem) {
            sumHead->next = new ListNode();
            sumHead = sumHead->next;
            sumHead->val = (carry + lRem->val) % 10;
            carry = (carry + lRem->val) / 10;
            lRem=lRem->next;
        }
        if (carry) {
            sumHead->next = new ListNode();
            sumHead = sumHead->next;
            sumHead->val = (carry);
        }
        return sumOrigin;
    }
};