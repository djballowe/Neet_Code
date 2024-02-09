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

        for (int r = k - 1; r < nums.size(); r++) {
            if (r == k - 1 || nums[l - 1] == largest) {
                cout << r << ", " << "";
                largest = calculateLargest(nums, l, r);
            } else {
                largest = max(largest, nums[r]);
            }
            ans.push_back(largest);
            l++;
            //cout << largest << ", " << "";
        }
        return ans;
    }
};
