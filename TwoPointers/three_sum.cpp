#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int a = 0;

        while (a < nums.size()) {
            int b = a + 1;
            int c = nums.size() - 1;
            while (b < c) {
                if (nums[a] + nums[b] + nums[c] > 0) {
                    c--;
                } else if (nums[a] + nums[b] + nums[c] < 0) {
                    b++;
                } else {
                    vector<int> trip = {nums[a], nums[b], nums[c]};
                    if (a != b && b != c && a != c) {
                        ans.push_back(trip);
                    }
                    c--;
                    b++;
                }
            }
        }
        return ans;
    }
};
