#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int l = 0;
        int sum = 0;
        int smallest = INT_MAX;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                smallest = min(smallest, (r - l) + 1);
                sum -= nums[l];
                l++;
            }
        }
        return smallest == INT_MAX ? 0 : smallest;
    }
};
