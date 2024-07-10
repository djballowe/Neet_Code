#include <iostream>
#include <queue>
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
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        int level = 1;
        vector<int> order;
        q.push(root);

        while (!q.empty()) {
            TreeNode *currNode = q.front();
            order.push_back(currNode->val);
            q.pop();
            if (currNode->left) {
                q.push(currNode->left);
                cout << currNode->left->val << endl;
            }
            if (currNode->right) {
                q.push(currNode->right);
                cout << currNode->right->val << endl;
            }
            if (currNode->left->left != currNode->right->right) {
                return false;
            }
        }

        return true;
    }
};
