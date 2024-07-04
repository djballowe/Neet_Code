#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        map<string, int> cities;
        int n = paths.size();

        for (int i = 0; i < n; i++) {
            cities[paths[i][0]]++;
        }

        for (int i = 0; i < n; i++) {
            if (!cities[paths[i][1]]) {
                return paths[i][1];
            }
        }
        return "No City Found";
    }
};
