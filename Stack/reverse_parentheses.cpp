#include <algorithm>
#include <deque>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        deque<string> stack;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                stack.push_back(ans);
                ans = "";
            } else if (s[i] == '(') {
                reverse(ans.begin(), ans.end());
                ans = stack.back() + ans;
                stack.pop_back();
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};
