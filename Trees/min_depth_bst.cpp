#include <algorithm>

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
private:
    int ans = 1000000;

    bool dfs(TreeNode *root, int count) {
        if (!root) {
            return false;
        }

        count++;
        if (!root->right && !root->left) {
            ans = std::min(count, ans);
        }

        return dfs(root->right, count) || dfs(root->left, count);
    }

public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int count = 0;
        dfs(root, count);
        return ans;
    }
};
