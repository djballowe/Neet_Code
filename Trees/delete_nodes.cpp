#include <map>
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
    map<int, int> toDelete;
    map<TreeNode *, TreeNode *> roots;

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> ans;
        roots[root] = root;

        for (int i = 0; i < to_delete.size(); i++) {
            toDelete[to_delete[i]] = to_delete[i];
        }

        dfs(root);

        for (const auto &pair : roots) {
            ans.push_back(pair.second);
        }

        return ans;
    }

private:
    TreeNode *dfs(TreeNode *root) {
        if (!root) {
            return nullptr;
        }

        TreeNode *res = root;
        if (toDelete[root->val]) {
            res = nullptr;
            roots.erase(root);
            if (root->right) {
                roots[root->right] = root->right;
            }
            if (root->left) {
                roots[root->left] = root->left;
            }
        }

        root->left = dfs(root->left);
        root->right = dfs(root->right);
        return res;
    }
};
