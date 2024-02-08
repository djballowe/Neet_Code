#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    int hasChars(vector<int> &freq) { return false; }

public:
    int minWindow(string s, string t) {
        unordered_map<char, int> map;
        int l = 0;
        int r = 0;
        int shortest = s.size();

        for (int i = 0; i < t.size(); i++) {
            map.find(t[i]) != map.end() ? map[t[i]] += 1 : map[t[i]] = 1;
        }

        for (const auto& pair : map) {
            cout << pair.first << ":" << pair.second << "\n";
        }

        while (r < s.size()) {

        }

        return 1;
    }
};
