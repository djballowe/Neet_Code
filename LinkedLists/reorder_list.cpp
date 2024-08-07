#include <deque>
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
    void reorderList(ListNode *head) {
        deque<ListNode *> list;
        ListNode *pointer = head;

        while (pointer) {
            list.push_back(pointer);
            pointer = pointer->next;
        }

        int count = 1;
        pointer = head;
        list.pop_front();

        while (list.size()) {
            if (count % 2 != 0) {
                pointer->next = list.back();
                list.pop_back();
            } else {
                pointer->next = list.front();
                list.pop_front();
            }
            cout << pointer->val << endl;
            cout << list.back()->val << endl;
            count++;
            pointer = pointer->next;
        }

        pointer->next = nullptr;

        return;
    }
};
