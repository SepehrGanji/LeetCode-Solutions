class Solution {
public:
    int hammingWeight(int n) {
        unsigned int count = 0;
        while (n > 0) {           // until all bits are zero
            if ((n & 1) == 1)     // check lower bit
                count++;
            n >>= 1;              // shift bits, removing lower bit
        }
        return count;
    }
};
