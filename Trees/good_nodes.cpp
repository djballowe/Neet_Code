#include <algorithm>
#include <iostream>

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
    int goodNodes(TreeNode *root) {
        int max = root->val;
        dfs(root, max);
        return ans;
    }

private:
    int ans = 0;
    void dfs(TreeNode *root, int max) {
        if (!root) {
            return;
        }

        max = std::max(max, root->val);
        if (root->val >= max) {
            ans++;
        }


        dfs(root->right, max);
        std::cout << root->val << std::endl;
        dfs(root->left, max);

        return;
    }
};
