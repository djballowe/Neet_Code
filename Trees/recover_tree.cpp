#include <iostream>
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

public:
    void recoverTree(TreeNode *root) {
        dfs(root);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }

    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }

        recoverTree(root->left);
        ans.push_back(root->val);
        recoverTree(root->right);
    }
};
