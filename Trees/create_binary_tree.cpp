#include <map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        map<TreeNode *, TreeNode *> nodes;
        map<int, TreeNode *> map;
        for (int i = 0; i < descriptions.size(); i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            TreeNode *p =
                map[parent] ? map[parent] : map[parent] = new TreeNode(parent);
            TreeNode *c =
                map[child] ? map[child] : map[child] = new TreeNode(child);
            isLeft ? p->left = c : p->right = c;
            nodes[c] = p;
        }
        TreeNode *pointer = nodes.begin()->second;
        while (nodes[pointer]) {
            pointer = nodes[pointer];
        }
        return pointer;
    }
};
