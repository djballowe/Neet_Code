#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int checkInclusion(string s1, string s2) {
        vector<int> freq(26);
        int l = 0;
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        for (int r = 0; r < s2.size(); r++) {
            cout << freq[s2[r] - 'a'] << "\n";
            if (freq[s2[r] - 'a'] > 0 && s1[r - l] == s2[r]) {
                //cout << s2[r] << endl;
            } else {
                l = r;
            }
        }

        return 1;
    }
};

// "eidboaoo"
// "eidbaooo"
