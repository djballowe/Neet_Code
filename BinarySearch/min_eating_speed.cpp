#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        auto max = std::max_element(piles.begin(), piles.end());

        int l = 1;
        int r = *max;

        int res = r;
        cout << r << endl;

        while (l <= r) {
            int m = l + (r - l) / 2;
            long int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += std::ceil((double) piles[i] / m);
            }
            if (hours <= h) {
                res = std::min(res, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
