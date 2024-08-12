#include <cstdlib>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, ListNode *> list;

        ListNode *currNode = headA;

        while (currNode) {
            list[currNode] = currNode;
            currNode = currNode->next;
        }

        currNode = headB;

        while (currNode) {
            if (list[currNode]) {
                return currNode;
            }
            currNode = currNode->next;
        }

        return nullptr;
    }
};
