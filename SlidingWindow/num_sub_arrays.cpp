#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int sum = 0;
        int average = 0;
        int ans = 0;
        int l = 0;

        for (int r = 0; r < arr.size(); r++) {
            sum += arr[r];
            if ((r - l) + 1 == k) {
                average = sum / k;
                if (average >= threshold) {
                    ans++;
                }
                sum -= arr[l++];
            }
        }

        return ans;
    }
};
