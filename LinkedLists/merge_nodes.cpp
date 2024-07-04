struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *ans = new ListNode(0);
        ListNode *iter = ans;
        ListNode *currNode = head->next;
        int sum = 0;

        while (currNode) {
            if (currNode->val) {
                sum += currNode->val;
            } else {
                iter->next = new ListNode(sum);
                iter = iter->next;
                sum = 0;
            }
            currNode = currNode->next;
        }
        return ans->next;
    }
};
