#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<string> &logs) {
        stack<int> stk;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (logs[i] == "./") {
                continue;
            } else {
                stk.push(1);
            }
        }
        return stk.size();
    }
};
