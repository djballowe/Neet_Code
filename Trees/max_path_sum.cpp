#include <algorithm>
#include <climits>
#include <iostream>

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
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &ans) {
        if (!root) {
            return 0;
        }

        int l = max(0, dfs(root->left, ans));
        int r = max(0, dfs(root->right, ans));
        ans = max(root->val + r + l, ans);
        return root->val + max(l, r);
    }
};
