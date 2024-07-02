#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> pairs;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            pairs[nums1[i]] += 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (pairs[nums2[i]]) {
                ans.push_back(nums2[i]);
                pairs[nums2[i]]--;
            }
        }
        return ans;
    }
};
