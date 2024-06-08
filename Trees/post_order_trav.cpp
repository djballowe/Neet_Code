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
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) {
            return ans;
        }

        ans = postorderTraversal(root->right);
        ans = postorderTraversal(root->left);
        ans.push_back(root->val);
        return ans;
    }
};
