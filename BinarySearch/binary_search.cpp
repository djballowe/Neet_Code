#include <cstdint>
#include <vector>

class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return -1;
    }
};
