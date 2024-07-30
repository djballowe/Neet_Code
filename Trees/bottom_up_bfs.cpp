#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans; 
        if (!root) {
            return ans;
        }

        deque<TreeNode*> q; 
        q.push_front(root);


        while (q.size()) {
            int qsize = q.size();
            vector<int> levels;

            for (int i = 0; i < qsize; i++) {
                TreeNode* currNode = q.back();
                q.pop_back();

                if (currNode->left) {
                    q.push_front(currNode->left);
                }
                if (currNode->right) {
                    q.push_front(currNode->right);
                }
                levels.push_back(currNode->val);
            }
            ans.push_back(levels);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
