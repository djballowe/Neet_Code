#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> map;

public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int longest = 0;

        for (int r = 0; r < s.size(); r++) {
            while (map.find(s[r]) != map.end()) {
                map.erase(s[l]);
                l++;
            }
            map[s[r]] = r;
            longest = max(longest, (r - l) + 1);
        }
        return map.empty() ? 0 : longest;
    }
};
