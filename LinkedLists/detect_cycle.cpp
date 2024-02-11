struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return head;

        bool hasCycle = false;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        ListNode *slow2 = head;

        if (hasCycle) {
            while (slow != slow2) {
                slow = slow->next;
                slow2 = slow2->next;
            }
        }

        return hasCycle ? slow : nullptr;
    }
};
