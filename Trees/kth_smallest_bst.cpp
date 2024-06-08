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
    int kthSmallest(TreeNode *root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &k, int &ans) {
        if (!root) {
            return 0;
        }

        dfs(root->left, k, ans);
        k--;
        if (k == 0) {
            ans = root->val;
            return root->val;
        }
        dfs(root->right, k, ans);
        return 0;
    }
};
