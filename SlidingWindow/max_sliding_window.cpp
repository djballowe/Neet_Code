#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        deque<int> deque;
        int l = 0;
        int r = 0;

        while (r < nums.size()) {
            while (!deque.empty() && nums[r] > deque.back()) {
                deque.pop_back();
            }

            deque.push_back(nums[r]);

            if (r + 1 >= k) {
                ans.push_back(deque.front());
                if (nums[l] == deque.front()) {
                    deque.pop_front();
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
