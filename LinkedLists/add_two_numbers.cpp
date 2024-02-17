#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode();
        ListNode *newList = ans;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int val1 = !l1 ? 0 : l1->val;
            int val2 = !l2 ? 0 : l2->val;

            int sum = val1 + val2 + carry;

            newList->next = new ListNode(sum % 10);
            newList = newList->next;

            carry = sum / 10;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        if (carry == 1) {
            newList->next = new ListNode(1);
        }

        return ans->next;
    }
};
