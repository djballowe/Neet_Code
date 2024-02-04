#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int cheapest = prices[0];
        int l = 0;
        int max_profit = 0;

        for (int r = 0; r < prices.size(); r++) {
            if (cheapest > prices[r]) {
                cheapest = prices[r];
                l = r;
            }
            max_profit = max(prices[r] - prices[l], max_profit);
        }
        return max_profit;
    }
};
