#include <algorithm>
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
private:
    int max;
public:
    int maxPathSum(TreeNode *root) {
        int max = 0;
        dfs(root, max);
        return max;
    }

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }


        int l = std::max(dfs(root->left), 0);
        int r = std::max(dfs(root->right), 0);
        int newVal = root->val + l + r;
        max = std::max(max, newVal)


        return 1;
    }
};
