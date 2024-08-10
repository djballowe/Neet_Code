#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    vector<int> sorted;

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        traverseList(list1);
        traverseList(list2);

        sort(sorted.begin(), sorted.end());

        if (!sorted.size()) {
            return {};
        }

        ListNode *head = new ListNode(sorted[0]);
        ListNode *currNode = head;

        for (int i = 1; i < sorted.size(); i++) {
            currNode->next = new ListNode(sorted[i]);
            currNode = currNode->next;
        }

        return head;
    }

private:
    void traverseList(ListNode *head) {
        ListNode *currNode = head;

        while (currNode) {
            sorted.push_back(currNode->val);
            currNode = currNode->next;
        }
    }
};
