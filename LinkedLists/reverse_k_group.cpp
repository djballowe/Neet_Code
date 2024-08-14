#include <iostream>

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *currNode = head;
        int listLen = 0;

        while (currNode) {
            listLen++;
            currNode = currNode->next;
        }

        int reverseCount = listLen / k;
        currNode = head;
        ListNode *prevNode = nullptr;

        while (reverseCount) {
            for (int i = 1; i < k; i++) {
                ListNode *temp = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = temp;
            }
            reverseCount--;
        }

        return head;
    }
};
