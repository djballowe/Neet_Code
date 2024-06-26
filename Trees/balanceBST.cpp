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
    vector<int> sorted;

public:
    TreeNode *balanceBST(TreeNode *root) {
        dfs(root);
        return createBST(0, sorted.size() - 1);
    }

private:
    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }

        dfs(root->left);
        sorted.push_back(root->val);
        dfs(root->right);
        return;
    }

    TreeNode *createBST(int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(sorted[mid]);
        root->left = createBST(start, mid - 1);
        root->right = createBST(mid + 1, end);
        return root;
    }
};
