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
    vector<int> arr1;
    vector<int> arr2;

    bool dfs(TreeNode *root, vector<int> &arr) {
        if (!root) {
            return false;
        }

        if (!root->right && !root->left) {
            arr.push_back(root->val);
        }

        return dfs(root->left, arr) || dfs(root->right, arr);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        dfs(root1, arr1);
        dfs(root2, arr2);
        return arr1 == arr2;
    }

};
