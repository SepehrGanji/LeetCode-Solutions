class Solution {
public:
    bool canAliceWin(int n) {
        int to_rem = 10;
        bool ans = false;
        while(1) {
            if(n < to_rem) return ans;
            n -= to_rem;
            to_rem--;
            ans = !ans;
        }
    }
};
