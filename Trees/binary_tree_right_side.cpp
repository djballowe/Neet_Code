#include <deque>
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
public:
    vector<int> rightSideView(TreeNode *root) {
        deque<TreeNode *> que;
        vector<int> ans;

        if (root) {
            que.push_back(root);
        }

        while (!que.empty()) {
            int size = que.size();
            int lastVal = 0;

            for (int i = 0; i < size; i++) {
                TreeNode *curr = que.front();
                que.pop_front();
                lastVal = curr->val;

                if (curr->left) {
                    que.push_back(curr->left);
                }
                if (curr->right) {
                    que.push_back(curr->right);
                }
            }
            ans.push_back(lastVal);
        }

        return ans;
    }
};
