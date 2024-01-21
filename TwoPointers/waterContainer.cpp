#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int heightLen = std::size(height);
        int area = 0;
        int l = 0;
        int r = heightLen - 1;
        while (l < r) {
            int h = height[l] < height[r] ? height[l] : height[r];
            area = std::max(area, h * (r - l));
            height[r] < height[l] ? r-- : l++;
        }
        return area;
    }
};
