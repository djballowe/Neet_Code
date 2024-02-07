#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> map;

public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        int largest = 0;

        for (int r = 0; r < s.size(); r++) {
            if (map.find(s[r]) != map.end()) {
                map[s[r]] += 1;
            } else {
                map[s[r]] = 1;
            }
            largest = max(largest, map[s[r]]);
            if (r - l + 1 - largest > k) {
                map[s[l]] -= 1;
                l++;
            }
            ans = max(ans, (r - l) + 1);
        }
        return ans;
    }
};

// "AABABBA"
