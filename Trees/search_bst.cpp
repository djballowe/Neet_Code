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
    TreeNode *searchBST(TreeNode *root, int val) {
        TreeNode *currNode = root;
        while (currNode) {
            if (currNode->val == val) {
                return currNode;
            }
            currNode = val > currNode->val ? currNode->right : currNode->left;
        }
        return currNode;
    }
};
