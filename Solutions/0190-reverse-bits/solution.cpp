class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int en = 32;
        while(en-- > 0) {
            ans *= 2;
            ans += (n % 2);
            n /= 2;
        }
        return ans;
    }
};
