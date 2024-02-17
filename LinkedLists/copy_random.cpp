#include <cstddef>
#include <unordered_map>

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
        std::unordered_map<Node *, Node *> map;
        Node *currNode = head;

        while (currNode) {
            map[currNode] = new Node(currNode->val);
            currNode = currNode->next;
        }

        currNode = head;
        while (currNode) {
            Node *newNode = map[currNode];
            newNode->next = map[currNode->next];
            newNode->random = map[currNode->random];
            currNode = currNode->next;
        }

        return map[head];
    }
};
