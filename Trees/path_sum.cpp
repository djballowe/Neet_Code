
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
private:
    bool dfs(TreeNode *root, int targetSum, int sum) {
        if (!root) {
            return false;
        }

        if (!root->right && !root->left) {
            sum += root->val;
            if (sum == targetSum) {
                return true;
            }
        }

        return dfs(root->right, targetSum, sum + root->val) ||
               dfs(root->left, targetSum, sum + root->val);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        int sum = 0;
        return dfs(root, targetSum, sum);
    }
};
