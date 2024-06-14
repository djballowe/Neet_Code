#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 1; i < nums.size(); i++) {
            int offset = nums[i] - nums[i - 1] - 1;
            if (offset <= 0) {
                nums[i] -= offset;
                count -= offset;
            }
        }

        return count;
    }
};
