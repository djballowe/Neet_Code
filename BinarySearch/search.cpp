#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            std::cout << nums[m] << std::endl;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] >= nums[l]) {
                if (target > nums[m] || target < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
