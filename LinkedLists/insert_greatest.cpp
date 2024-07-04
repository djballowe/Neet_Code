struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *currNode = head;
        ListNode *nextNode = currNode->next;

        while (nextNode) {
            int val = gcd(currNode->val, nextNode->val);
            currNode->next = new ListNode(val);
            currNode->next->next = nextNode;
            currNode = nextNode;
            nextNode = nextNode->next;
        }

        return head;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
