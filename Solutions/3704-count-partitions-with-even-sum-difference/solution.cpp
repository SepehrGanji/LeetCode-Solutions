class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pfx(n, 0);
        pfx[0] = nums[0];
        for(int i = 1 ; i < n ; i++) pfx[i] = pfx[i-1] + nums[i];
        int su = pfx[n-1];
        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            if((pfx[i] - (su - pfx[i])) % 2 == 0) ans++;
        }
        return ans;
    }
};
