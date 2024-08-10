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
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<int> sorted;
        for (int i = 0; i < lists.size(); i++) {
            ListNode *currNode = lists[i];
            while (currNode) {
                sorted.push_back(currNode->val);
                currNode = currNode->next;
            }
        }

        sort(sorted.begin(), sorted.end());

        if (!sorted.size()) {
            return nullptr;
        }

        ListNode *head = new ListNode(sorted[0]);
        ListNode *currNode = head;

        for (int i = 1; i < sorted.size(); i++) {
            currNode->next = new ListNode(sorted[i]);
            currNode = currNode->next;
        }

        return head;
    }
};
