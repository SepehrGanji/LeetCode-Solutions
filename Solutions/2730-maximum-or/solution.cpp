class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pfx(n);
        pfx[0] = nums[0];
        for(int i = 1 ; i < n ; i++) {
            pfx[i] = pfx[i-1] | nums[i];
        }
        vector<long long> sfx(n);
        sfx[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            sfx[i] = sfx[i+1] | nums[i];
        }
        long long ans = -1;
        // first el
        long long el = nums[0];
        el <<= k;
        if(n == 1) return el;
        ans = el | sfx[1];
        // between els
        for(int i = 1 ; i < n-1 ; i++) {
            long long el = nums[i];
            el <<= k;
            ans = max(ans, pfx[i-1] | el | sfx[i+1]);
        }
        // last el
        el = nums[n-1];
        el <<= k;
        ans = max(ans, el | pfx[n-2]);
        return ans;
    }
};

