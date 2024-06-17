#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int r = sqrt(c);
        int l = 0;

        int ans = 0;

        while (r > l) {
            ans = pow(r, 2) + pow(l, 2);

            if (ans == c) {
                return true;
            }
            if (ans < c) {
                l++;
            } else {
                r--;
            }
        }

        return false;
    }
};
