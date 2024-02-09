#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int hasChars(unordered_map<char, int> &map) {
        for (auto &pair : map) {
            if (pair.second > 0) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> map;
        int l = 0;
        int r = 0;
        string ans;
        pair<int, int> shortest = {0, s.size()};
        bool valid = false;

        for (int i = 0; i < t.size(); i++) {
            map.find(t[i]) != map.end() ? map[t[i]] += 1 : map[t[i]] = 1;
        }

        while (r < s.size()) {
            if (map.find(s[r]) != map.end()) {
                map[s[r]]--;
            }
            if (hasChars(map)) {
                while (hasChars(map)) {
                    valid = true;
                    if (shortest.second - shortest.first >= r - l + 1) {
                        shortest.first = l;
                        shortest.second = r;
                        cout << r << endl;
                    }
                    if (map.find(s[l]) != map.end()) {
                        map[s[l]]++;
                    }
                    l++;
                }
            }
            r++;
        }


        for (int i = shortest.first; i <= shortest.second; i++) {
            ans += s[i];
        }
        return valid ? ans : "";
    }
};
