struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        int nodes = 1;
        ListNode *head = new ListNode(nodes);
        ListNode *currNode = head;
        while (nodes < n) {
            currNode->next = new ListNode(++nodes);
            currNode = currNode->next;
        }
        currNode->next = head;

        ListNode *person = head;
        ListNode *prevNode = currNode;
        int count = 0;
        while (person->val != prevNode->val) {
            count = k;
            while (count > 1) {
                person = person->next;
                prevNode = prevNode->next;
                count--;
            }
            prevNode->next = person->next;
            person = prevNode->next;
        }

        return person->val;
    }
};
