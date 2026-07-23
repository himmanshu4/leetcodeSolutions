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
int indent = 0;

struct ScopeIndent {
    ScopeIndent() { indent++; }
    ~ScopeIndent() { indent--; }
};

#define DBG(msg) std::cout << std::string(indent * 2, ' ') << msg << '\n';
class Solution {
    // Reverses group if group is of size k;
    // Floor tests if size<k;
    // grouphead will point to the new head, groupTail the newTail;
    void reverseGroup(ListNode*(&groupHead), ListNode*(&groupTail), int k) {
        ScopeIndent _;

        // DBG("reverseGroup initial:" << groupHead->val << ", "
        //                             << groupTail->val);
        {
            auto curr = groupHead;
            for (int i = 0; i < k; i++) {
                if (!curr) {
                    groupTail = nullptr;
                    return;
                }
                curr = curr->next;
            }
        }
        groupTail = groupHead;
        ListNode *prev = nullptr, *curr = groupHead, *next;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        groupHead = prev;
        groupTail->next = next;
        // DBG("reverseGroup final:" << groupHead->val << ", " << groupTail->val);
        // DBG("groupTail->next:" << groupTail->next << "\n");
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode sentinel;
        sentinel.next = head;
        ListNode* groupTail = &sentinel;
        while (groupTail) {
            ScopeIndent _;
            // DBG("groupTail:" << groupTail);
            reverseGroup(groupTail->next, groupTail, k);
        }
        return sentinel.next;
    }
};