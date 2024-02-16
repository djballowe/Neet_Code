struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        ListNode *prev = head;
        ListNode *currNode = head;
        int count = 0;

        while (currNode) {
            if (count > n) {
                prev = prev->next;
            }
            currNode = currNode->next;
            count++;
        }

        if (count <= n) {
            head = head->next;
        } else { 
            prev->next = prev->next->next;
        }

        return head;
    }
};
