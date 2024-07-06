#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        string temp = word;
        int r = 0;
        int l = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                break;
            }
            l++;
        }

        if (l == word.size() - 1) {
            return word;
        }

        while (l >= 0) {
            word[l] = temp[r];
            l--;
            r++;
        }

        return word;
    }
};
