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
    ListNode* middleNode(ListNode* head) {
        auto candidate=head;
        auto leader = head;
        while(leader){
            leader=leader->next;
            if(leader){
                leader=leader->next;
                candidate=candidate->next;
            }
        }
        return candidate;
    }
};