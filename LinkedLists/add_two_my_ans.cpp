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
        ListNode *currNode = l1;
        int power = 1;
        int num1 = 0, num2 = 0;

        while (currNode) {
            num1 += currNode->val * power;
            power *= 10;
            currNode = currNode->next;
        }

        currNode = l2;
        power = 1;
        while (currNode) {
            num2 += currNode->val * power;
            power *= 10;
            currNode = currNode->next;
        }

        int result = num1 + num2;
        int len = std::to_string(result).length();


        ListNode *newList = new ListNode();
        ListNode *currNew = newList;

        unsigned long long mod = 10;
        int div = 1;

        while (len) {
            int digit = result % mod / div;
            currNew->val = digit;
            if (len == 1) {
                break;
            }
            currNew->next = new ListNode();
            currNew = currNew->next;
            div *= 10;
            mod *= 10;
            len--;
        }

        return newList;
    }
};
