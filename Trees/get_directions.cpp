#include <algorithm>
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
public:
    string getDirections(TreeNode *root, int startValue, int destValue) {
        string start = "";
        string end = "";
        string ans = "";
        dfs(root, startValue, start);
        dfs(root, destValue, end);
        int i = 0;
        while (i < min(start.size(), end.size())) {
            if (start[i] != end[i]) {
                break;
            }
            i++;
        }
        for (int j = i; j < start.size(); j++) {
            ans += "U";
        }
        for (int d = i; d < end.size(); d++) {
            ans += end[d];
        }
        return ans;
    }

private:
    string dfs(TreeNode *root, int t, string &path) {
        if (!root) {
            return "";
        }

        if (root->val == t) {
            return path;
        }

        path += "L";
        string res = dfs(root->left, t, path);
        if (res != "") {
            return res;
        }

        path.pop_back();
        path += "R";
        res = dfs(root->right, t, path);
        if (res != "") {
            return res;
        }

        path.pop_back();
        return "";
    }
};
