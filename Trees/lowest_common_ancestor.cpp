struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return dfs(root, p->val, q->val);
    }

private:
    TreeNode *dfs(TreeNode *root, int q, int p) {
        if (!root) {
            return nullptr;
        }

        if (root->val > p && root->val > q) {
            dfs(root->left, q, p);
        } else if (root->val < p && root->val > q) {
            dfs(root->right, q, p);
        }

        return root;
    }
};
