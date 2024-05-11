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

class Solution {
private:
    std:: vector<int> tree1;
    std:: vector<int> tree2;

    TreeNode *storeTree(TreeNode *root) {
            
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        storeTree(p);
        storeTree(q);
        if (tree1.size() != tree2.size()) {
            return false;
        }

        for (int i = 0; i < tree1.size(); i++) {
            if (tree1[i] != tree2[i]) {
                return false;
            }
        }

        return true;
    }

};
