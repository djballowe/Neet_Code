#include <string>
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
    int sum;

public:
    int sumNumbers(TreeNode *root) {
        string num;
        dfs(root, num);
        return sum;
    }

    bool dfs(TreeNode *root, string num) {
        if (!root) {
            return 0;
        }

        num += to_string(root->val);

        if (!root->right && !root->left) {
            int currNum = stoi(num);
            sum += currNum;
        }


        return dfs(root->left, num) || dfs(root->right, num);
    }
};

