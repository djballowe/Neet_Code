#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;

class Solution {
public:
    int trap(std::vector<int> &height) {
        std::vector<uint> stack;
        size_t i = 0;
        size_t l, r;
        uint waterTotal = 0, water = 0;
        uint maxHeight = std::numeric_limits<uint>::max();

        while (i < height.size()) {
            if (height[i] > height[i + 1]) {
                l = i;
                r = i + 1;
                stack.push_back(height[l]);
                maxHeight = height[i];
                int count = 0;
                while (height[r] < maxHeight) {
                    stack.push_back(height[r]);
                    r++;
                }
                for (int value : stack) {
                    std::cout << value << " ";
                }
                maxHeight = std::min(maxHeight, static_cast<uint>(height[r]));
                while (stack.size()) {
                    water = maxHeight - stack.back();
                    waterTotal += water;
                    stack.pop_back();
                }
                std::cout << "Total: " << waterTotal << std::endl;
                i = r;
            } else {
                i++;
            }
        }
        return waterTotal;
    }
};
