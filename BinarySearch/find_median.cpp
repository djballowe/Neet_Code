#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int small = nums1.size();
        int large = nums2.size();

        if (large < small) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = nums1.size() + nums2.size();

        int l = 0;
        int r = small;

        double res = 0.0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int j = (total + 1) / 2 - m;
            int small_left = m > 0 ? nums1[m - 1] : INT_MIN;
            int small_right = m < small ? nums1[m] : INT_MAX;
            int large_left = j > 0 ? nums2[j - 1] : INT_MIN;
            int large_right = j < large ? nums2[j] : INT_MAX;
            if (small_left <= large_right && large_left <= small_right) {
                if (total % 2 == 0) {
                    res = (max(large_left, small_left) +
                           min(large_right, small_right)) /
                          2.0;
                } else {
                    res = max(large_left, small_left);
                }
                break;
            } else if (small_left > large_right) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
