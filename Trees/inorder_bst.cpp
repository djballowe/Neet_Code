#include <algorithm>
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
    vector<int> ans;
    int i = 0;

public:
    void recoverTree(TreeNode *root) {
        dfs(root);
        sort(ans.begin(), ans.end());
        rebuild(root, i);
    }

    void rebuild(TreeNode *root, int &i) {
        if (!root) {
            return;
        }

        rebuild(root->left, i);
        root->val = ans[i++];
        rebuild(root->right, i);
        return;
    }

    vector<int> dfs(TreeNode *root) {
        if (!root) {
            return ans;
        }

        ans = dfs(root->left);
        ans.push_back(root->val);
        ans = dfs(root->right);
        return ans;
    }
};
