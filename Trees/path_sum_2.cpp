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
private:
    vector<vector<int>> ans;
    int targetSum{0};

    bool dfs(TreeNode *root, int sum, vector<int> path) {
        if (!root) {
            return false;
        }

        if (!root->right && !root->left) {
            sum += root->val;
            path.push_back(root->val);
            if (sum == targetSum) {
                ans.push_back(path);
            }
        }
        path.push_back(root->val);

        return dfs(root->right, sum + root->val, path) ||
               dfs(root->left, sum + root->val, path);
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        this->targetSum = targetSum;
        int sum = 0;
        vector<int> path;
        dfs(root, sum, path);
        return ans;
    }
};
