#include <string>

using namespace std;

class Solution {
    int score = 0;

public:
    int maximumGain(string s, int x, int y) {
        int greater = max(x, y);
        int less = min(x, y);
        string maxString = x > y ? "ab" : "ba";
        string minString = maxString == "ab" ? "ba" : "ab";
        string t = iterateString(s, greater, maxString);
        iterateString(t, less, minString);
        return score;
    }

    string iterateString(string s, int factor, string target) {
        string stack = "";
        for (int i = 0; i < s.size(); i++) {
            if (stack != "" && s[i] == target[1] && stack.back() == target[0]) {
                stack.pop_back();
                score += factor;
            } else {
                stack.push_back(s[i]);
            }
        }

        return stack;
    }
};
