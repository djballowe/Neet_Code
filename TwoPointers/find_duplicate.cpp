#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int fast = 0, slow = 0;

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        int slow2 = 0;

        do {
            slow = nums[slow];
            slow2 = nums[slow2];
        } while (slow2 != slow);

        return slow2;
    }
};
