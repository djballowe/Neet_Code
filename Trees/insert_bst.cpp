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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        TreeNode *currNode = root;

        if (!currNode) {
            return new TreeNode(val);
        }

        while (currNode) {
            if (val > currNode->val) {
                if (!currNode->right) {
                    currNode->right = new TreeNode(val);
                    break; 
                }
                currNode = currNode->right;
            } else {
                if (!currNode->left) {
                    currNode->left = new TreeNode(val);
                    break;
                }
                currNode = currNode->left;
            }
        }
        return root;
    }
};
