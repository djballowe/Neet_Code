#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 1; i < s.size(); i++) {
            int val = abs(s[i - 1] - s[i]);
            score += val;
        }

        return score;
    }
};
