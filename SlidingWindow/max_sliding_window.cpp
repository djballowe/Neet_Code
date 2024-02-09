#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int calculateLargest(vector<int> &nums, int l, int r) {
        int largest = 0;
        for (int i = l; i <= r; i++) {
            largest = max(largest, nums[i]);
        }
        return largest;
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        int l = 1;
        int largest = INT_MIN;

        for (int i = 0; i < k; i++) {
            largest = max(largest, nums[i]);
        }

        ans.push_back(largest);

        for (int r = k; r < nums.size(); r++) {
            if (nums[l - 1] == largest) {
                largest = calculateLargest(nums, l, r);
            } else if (nums[r] > largest) {
                largest = nums[r];
            }
            ans.push_back(largest);
            l++;
            cout << largest << "\n";
        }

        return ans;
    }
};
