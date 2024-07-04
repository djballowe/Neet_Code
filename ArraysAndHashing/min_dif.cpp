#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minDifference(vector<int> &nums) {
        if (nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int f = nums[3];
        int l = nums[n - 4];
        int d = nums[n - 1];
        int j = nums[n - 3];
        int x = nums[n - 2];
        int b = nums[2];
        int y = nums[1];
        int a = nums[0];

        return min({d - f, l - a, j - y, x - b});
    }
};
