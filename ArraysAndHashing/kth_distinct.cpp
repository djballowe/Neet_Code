#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string> &arr, int k) {
        string ans = "";
        map<string, int> freq;

        for (string strs : arr) {
            freq[strs]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (freq[arr[i]] == 1) {
                k--;
            }
            if (freq[arr[i]] == 1 && !k) {
                return arr[i];
            }
        }

        return ans;
    }
};
