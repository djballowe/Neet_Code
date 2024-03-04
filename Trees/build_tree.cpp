#include <vector>

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
    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, int &index, int i, int j) {
        if (i > j) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[index]);
        int mid = 0;

        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[index]) {
                mid = i;
                break;
            }
        }
        index++;

        root->left = construct(preorder, inorder, index, i, mid - 1);
        root->right = construct(preorder, inorder, index, mid + 1, j);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int index = 0;

        return construct(preorder, inorder, index, 0, inorder.size() - 1);
    }
};

