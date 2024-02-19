#include <unordered_map>
class Node {
public:
    Node *next;
    Node *prev;
    int val;
    int key;
    Node(int val, int key) {
        key = key;
        val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {

public:
    LRUCache(int capacity) {
        cap = capacity;

        right = new Node(0, 0);
        left = new Node(0, 0);

        right->prev = left;
        left->next = right;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }

        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > cap) {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

private:
    int cap;
    Node *right;
    Node *left;
    std::unordered_map<int, Node *> cache;

    void remove(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node) {
        Node *prev = right->prev;
        Node *next = right;

        prev->next = node;
        next->prev = node;

        node->prev = prev;
        node->next = next;
    }
};
