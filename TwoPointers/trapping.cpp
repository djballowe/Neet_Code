#include <algorithm>
#include <cstdlib>
#include <vector>

typedef unsigned int uint;
// TODO do this with two pointer 

class Solution {
public:
    int trap(std::vector<int> &height) {
        size_t n = height.size();
        int *left = static_cast<int *>(std::malloc(sizeof(int) * n)),
            *right = static_cast<int *>(std::malloc(sizeof(int) * n)),
            *diff = static_cast<int *>(std::malloc(sizeof(int) * n));
        int maxLeft = 0, maxRight = 0, waterTotal = 0;

        for (int i = 0; i < height.size(); i++) {
            maxLeft = i == 0 ? 0 : std::max(maxLeft, height[i - 1]);
            left[i] = maxLeft;
        }

        for (int i = n - 1; i >= 0; i--) {
            maxRight = i == n - 1 ? 0 : std::max(maxRight, height[i + 1]);
            right[i] = maxRight;
        }

        for (int i = 0; i < n; i++) {
            diff[i] = std::min(left[i], right[i]);
        }

        for (int i = 0; i < n; i++) {
            int water = diff[i] - height[i];
            waterTotal += water <= 0 ? 0 : water;
        }

        std::free(left);
        std::free(right);
        std::free(diff);

        return waterTotal;
    }
};
