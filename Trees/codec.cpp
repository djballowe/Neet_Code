#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        stringstream s(data);

        return buildTree(s);
    }

private:
    TreeNode *buildTree(stringstream &s) {
        string str;
        getline(s, str, ',');

        if (str == "n") {
            return nullptr;
        } else {
            TreeNode *node = new TreeNode(stoi(str));
            node->left = buildTree(s);
            node->right = buildTree(s);
            return node;
        }
    }

    void dfs(TreeNode *root, string &ans) {
        if (!root) {
            ans.append("n,");
            return;
        }

        ans.append(to_string(root->val) + ',');
        dfs(root->left, ans);
        dfs(root->right, ans);
        return;
    }
};
