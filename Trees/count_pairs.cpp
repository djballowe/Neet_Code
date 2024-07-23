#include <string>
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
    vector<string> paths;

public:
    int countPairs(TreeNode *root, int distance) {
        string currPath = "";
        int ans = 0;
        int steps = 0;
        dfs(root, currPath);
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths.size(); j++) {
                steps = 0;
                int d = 0;
                while (d < min(paths[i].size(), paths[j].size())) {
                    if (paths[i][d] != paths[j][d]) {
                        break;
                    }
                    d++;
                }
                steps = (paths[i].size() - d) + (paths[j].size() - d);
                if (steps && steps <= distance) {
                    ans++;
                }
            }
        }
        return ans / 2;
    }

    string dfs(TreeNode *root, string path) {
        if (!root) {
            return "";
        }

        if (!root->right && !root->left) {
            paths.push_back(path);
        }

        path += "L";
        string res = dfs(root->left, path);
        if (res != "") {
            return res;
        }

        path.pop_back();
        path += "R";
        res = dfs(root->right, path);
        if (res != "") {
            return res;
        }

        path.pop_back();
        return "";
    }
};
