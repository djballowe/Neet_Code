#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        int ans = 0;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prevNode = nullptr;
        ListNode *currNode = slow;


        while (currNode) {
            ListNode *temp = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = temp;
        }

        slow = head;
        ListNode *twinHead = prevNode;

        while (twinHead) {
            ans = max(slow->val + twinHead->val, ans);
            slow = slow->next;
            twinHead = twinHead->next;
        }

        return ans;
    }
};
