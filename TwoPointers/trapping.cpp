#include <iostream>
#include <vector>

typedef unsigned int uint;

class Solution {
public:
    int trap(std::vector<int> &height) {
        std::vector<int> stack;
        size_t i = 0;
        size_t l, r;
        uint waterTotal = 0, water = 0, maxHeight = 0;
        while (i < height.size()) {
            if (height[i] > height[i + 1]) {
                l = i;
                r = i + 1;
                stack.push_back(height[l]);
                while (height[r] < stack.back()) {
                    stack.push_back(height[r]);
                    r++;
                }
                for (int value : stack) {
                    std::cout << value << " ";
                }
                maxHeight = height[r];
                while (stack.size()) {
                    if (stack.back() < maxHeight) {
                        water = maxHeight - stack.back();
                        waterTotal += water;
                    }
                    stack.pop_back();
                }
                i = r;
            } else {
                i++;
            }
        }
        return waterTotal;
    }
};
