#include <queue>
#include <vector>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

public:
    KthLargest(int k, vector<int> &nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        while (pq.size() > size) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > size) {
            pq.pop();
        }

        return pq.top();
    }
};
