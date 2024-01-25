#include <cstdint>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
private: 
    int getInnerIndex(int l, int r) {
        return 1;
    }

public: 
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        uint32_t l = 0, r = matrix.back().size(), inner = matrix[0].size();
        cout << r << '\n';

        while (l <= r) {
            int m = l + (r + l) / 2;
            int l_outer = l / inner;
            int l_inner = inner * (l / inner);
            int l_index[2] = {l_outer, l_inner }; 
            int r_index = r / matrix[0].size();

        }
        return true;
    }
};
