#include <algorithm>
#include <limits>
#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int min = std::numeric_limits<int>::max();

        while (l <= r) {
            int m = l + (r - l) / 2;
            min = std::min(nums[m], min);
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return min;
    }
};
