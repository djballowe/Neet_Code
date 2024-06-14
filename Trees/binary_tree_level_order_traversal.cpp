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
    vector<vector<int>> levelOrder(TreeNode *root) {
        deque<TreeNode *> que;
        vector<vector<int>> ans;

        if (root) {
            que.push_front(root);
        }

        while (!que.empty()) {
            vector<int> level;
            int qsize = que.size();

            for (int i = 0; i < qsize; i++) {
                TreeNode *curr = que.front();
                que.pop_front();
                level.push_back(curr->val);

                if (curr->left) {
                    que.push_back(curr->left);
                }
                if (curr->right) {
                    que.push_back(curr->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
