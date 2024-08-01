#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string> &details) {
        int ans = 0;

        for (string detail : details) {
            string num_string = "";
            num_string += detail[11];
            num_string += detail[12];
            if (stoi(num_string) > 60) {
                ans++;
            }
        }

        return ans;
    }
};
