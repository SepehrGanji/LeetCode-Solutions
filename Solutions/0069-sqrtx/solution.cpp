class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        long long ans = 1;
        while(1) {
            if(ans * ans == x) return ans;
            else if(ans * ans > x) return ans-1;
            ans++;
        }
    }
};
