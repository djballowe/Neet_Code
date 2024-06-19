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
    bool isValidBST(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i - 1] >= ans[i]) {
                return false;
            }
        }
        return true;
    }

    bool dfs(TreeNode *root, vector<int> &ans) {
        if (!root) {
            return false;
        }

        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
        return true;
    }
};
