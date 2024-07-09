#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        double time = 0.00;
        double sum = 0.00;
        int n = customers.size();

        for (int i = 0; i < n; i++) {
            time = time > customers[i][0] ? time + customers[i][1]
                                          : customers[i][0] + customers[i][1];
            sum += time - customers[i][0];
        }

        return sum / n;
    }
};
