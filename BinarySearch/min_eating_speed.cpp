#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        auto max = std::max_element(piles.begin(), piles.end());
        
        int l = piles.size();
        int r = *max;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int bph = canEat(m, h, piles);
            if (bph == 0) {
                return m;
            } else if (bph > 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }

        }
        return 1;        
    }

private:
    int canEat(int m, int h, vector<int> &piles) {
        vector<int> tempPiles = piles;
        int tempHours = h;
        for (int i = 0; i < tempPiles.size(); i++) {
            while (tempPiles[i] > 0 && tempHours > 0) {
                tempPiles[i] -= m;
                tempHours--;
            }
            if (tempHours == 0 && i != tempPiles.size() - 1) {
                return -1;
            }
        }
        cout << m << " : " << tempHours << endl;
        return tempHours > 0 ? 1 : 0;
    }
};
