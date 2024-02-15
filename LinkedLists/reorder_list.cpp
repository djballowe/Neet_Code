struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *middle = nullptr;
        ListNode *currNode = slow;

        while (currNode) {
            ListNode *temp = currNode->next;
            currNode->next = middle;
            middle = currNode;
            currNode = temp;
        }

        currNode = head;

        while (middle->next) {
            ListNode *temp = currNode->next;
            ListNode *midTemp = middle->next;
            currNode->next = middle;
            middle->next = temp;
            currNode = temp;
            middle = midTemp;
        }
    }
};
