// TODO do this again you absolute loser
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int isValid(vector<int> &freq) {
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }

public:
    int checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> freq(26);
       
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;      
        }

        if (isValid(freq)) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            freq[s2[i] - 'a']--;
            freq[s2[i - s1.size()] - 'a']++;
            if (isValid(freq)) {
                return true;
            }
        }
        return false;
    }
};

