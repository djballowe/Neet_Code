#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        set<int> values;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if ((r - l) + 1 > k + 1) {
                values.erase(nums[l]);
                l++;
            }
            auto element = values.find(nums[r]);
            if (element != values.end()) {
                return true;
            }
            values.insert(nums[r]);
        }
        return false;
    }
};
