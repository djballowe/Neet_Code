#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

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
        vector<string> serial;
        string str = "";
        dfs(root, serial);
        for (int i = 0; i < serial.size(); i++) {
            if (serial[i] == "null") {
                str += "1001,";
            } else {
                str += serial[i] + ",";
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (!data.size()) {
            return nullptr;
        }
        vector<int> arr = convertArray(data);

        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;

        while (i < arr.size()) {
            if (arr[i] != 1001) {
                TreeNode *curr = q.front();
                q.pop();
                if (i < arr.size()) {
                    curr->left = new TreeNode(arr[i++]);
                    q.push(curr->left);
                }
                if (i < arr.size() && arr[i] != 1001) {
                    curr->right = new TreeNode(arr[i++]);
                    q.push(curr->right);
                }
            }
        }

        return root;
    }

private:
    void dfs(TreeNode *root, vector<string> &serial) {
        if (!root) {
            serial.push_back("null");
            return;
        }

        serial.push_back(to_string(root->val));
        dfs(root->left, serial);
        dfs(root->right, serial);
        return;
    }

    vector<int> convertArray(string data) {
        vector<int> arr;
        stringstream ss(data);
        string item;

        while (getline(ss, item, ',')) {
            arr.push_back(stoi(item));
        }

        return arr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
