#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int> &arr) {
        int count = 0;
        for (int val : arr) {
            val % 2 != 0 ? count++ : count = 0;
            if (count == 3) {
                return true;
            }
        }
        return false;
    }
};
