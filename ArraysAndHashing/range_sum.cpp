#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        int ans = 0;
        int mod = 1e9 + 7;
        vector<int> sumArr;

        for (int i = 0; i < nums.size(); i++) {
            long sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                sumArr.push_back(sum);
            }
        }

        sort(sumArr.begin(), sumArr.end());

        for (int i = left - 1; i < right; i++) {
            ans = (ans + sumArr[i]) % mod;
        }

        return ans;
    }
};
