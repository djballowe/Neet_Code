#include <cstdint>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int top = 0;
        int bot = matrix.size() - 1;

        while (top < bot) {
            int mid = top + (bot - top) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target &&
                matrix[mid + 1][0] > target) {
                top = mid;
                break;
            } else if (matrix[mid][0] < target) {
                top = mid + 1;
            } else {
                bot = mid - 1;
            }
        }
        cout << top << bot << endl;

        int l = 0;
        int r = matrix[0].size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[top][m] > target) {
                r = m - 1;
            } else if (matrix[top][m] < target) {
                l = m + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
