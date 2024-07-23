#include <climits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        vector<pair<int, int>> small;
        vector<int> ans;

        for (int i = 0; i < matrix.size(); i++) {
            int minimum = INT_MAX;
            pair<int, int> p;
            int col;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (minimum > matrix[i][j]) {
                    minimum = matrix[i][j];
                    col = j;
                }
            }
            p.first = minimum;
            p.second = col;
            small.push_back(p);
        }

        for (int i = 0; i < small.size(); i++) {
            int maximum = INT_MIN;
            int col = small[i].second;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][col] > maximum) {
                    maximum = matrix[j][col];
                }
            }
            if (maximum == small[i].first) {
                ans.push_back(maximum);
            }
        }

        return ans;
    }
};
