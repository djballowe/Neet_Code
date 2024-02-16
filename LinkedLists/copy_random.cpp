#include <cstddef>

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        Node *copy = new Node(head->val);
        Node *currNode = head;

        while (currNode) {
            currNode = currNode->next;
            copy->next = currNode;
        }
    }
};
