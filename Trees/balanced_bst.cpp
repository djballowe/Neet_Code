#include <algorithm>
#include <cstdlib>
#include <utility>

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
    bool isBalanced(TreeNode *root) {
        int count = 0;
        pair<bool, int> ans = dfs(root);
        return ans.first;
    }

    pair<bool, int> dfs(TreeNode *root) {
        if (!root) {
            return {true, 0};
        }

        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);

        bool balance = left.first && right.first && abs(left.second - right.second) <= 1;

        return { balance, 1 + max(left.second, right.second) };
    }
};
