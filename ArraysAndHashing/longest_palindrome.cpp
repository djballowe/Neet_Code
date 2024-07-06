#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> freq;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]] += 1;
            if (freq[s[i]] % 2 == 0) {
                ans += 2;
            }
        }
        return s.size() > ans ? ans + 1 : ans;
    }
};
