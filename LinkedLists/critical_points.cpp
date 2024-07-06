#include <algorithm>
#include <climits>
#include <iostream>
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> ans = {-1, -1};
        vector<int> test = {INT_MIN, INT_MAX};
        vector<int> nodes;
        int min = INT_MAX;
        int count = 2;
        if (!head || !head->next || !head->next->next) {
            return ans;
        }

        ListNode *currNode = head->next;
        ListNode *nextNode = currNode->next;
        ListNode *prevNode = head;

        while (nextNode) {
            if (currNode->val > nextNode->val &&
                currNode->val > prevNode->val) {
                nodes.push_back(count);
            }
            if (currNode->val < nextNode->val &&
                currNode->val < prevNode->val) {
                nodes.push_back(count);
            }
            if (nodes.size() >= 2) {
                min = std::min(min, nodes[nodes.size() - 1] -
                                        nodes[nodes.size() - 2]);
            }
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
            count++;
        }

        if (nodes.size()) {
            ans[1] = nodes[nodes.size() - 1] - nodes[0];
            ans[0] = min == INT_MAX ? -1 : min;
        }

        return ans;
    }
};
