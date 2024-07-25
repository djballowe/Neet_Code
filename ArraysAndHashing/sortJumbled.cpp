#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        vector<int> ans;
        vector<pair<int, int>> mapped;
        string curNum = "";

        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            while (number) {
                int digit = number % 10;
                curNum += to_string(mapping[digit]);
                number /= 10;
            }
            if (curNum == "") {
                curNum += to_string(mapping[0]);
            }
            reverse(curNum.begin(), curNum.end());
            pair<int, int> keyVal = {nums[i], stoi(curNum)};
            mapped.push_back(keyVal);
            curNum = "";
        }

        sort(mapped.begin(), mapped.end(), cmp);

        for (const auto &pair : mapped) {
            ans.push_back(pair.first);
        }

        return ans;
    }

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};
