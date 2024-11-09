class Solution {
public:

    long long __gcd(long long a, long long b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        if (a == b)
            return a;

        if (a > b)
        return gcd(a - b, b);


        return gcd(a, b - a);
    }

    long long calc(int noIdx, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) {
            if(noIdx == -1) return nums[0] * nums[0];
            return 0;
        }
        long long gcd = noIdx == 0 ? nums[1] : nums[0];
        long long lcm = gcd;
        for(int i = 0 ; i < n ; i++) {
            if(i != noIdx) {
                gcd = __gcd(gcd, nums[i]);
                lcm = (lcm * nums[i]) / __gcd(lcm, nums[i]);
            }
        }
        cout << "NoIdx: " << noIdx << " && lcm+gcd:" << lcm << ',' << gcd << endl;

        return lcm * gcd;
    }

    long long maxScore(vector<int>& nums) {
        long long ans = calc(-1, nums);
        for(int i = 0 ; i < nums.size() ; i++) {
            ans = max(ans, calc(i, nums));
        }
        return ans;
    }
};
