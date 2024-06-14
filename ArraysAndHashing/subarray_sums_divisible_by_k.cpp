#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        vector<int> prefix;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix.push_back(sum);
            if (sum % k == 0) {
                ans++;
            }
        }

        int n = nums.size();
        int i = 0;
        int j = 1;

        while (i < n) {
            while (j < n) {
                if ((prefix[j] - prefix[i]) % k == 0) {
                    ans++;
                }
                j++;
            }
            i++;
            j = i + 1;
        }

        return ans;
    }
};
