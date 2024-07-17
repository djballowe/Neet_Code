class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 1;
        while (count < n) {
            if (count == n) {
                return true;
            }
            count *= 2;
        }
        return false;
    }
};
