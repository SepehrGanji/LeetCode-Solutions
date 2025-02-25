class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> eve(n, 0), odd(n, 0);
        if(arr[0] % 2 == 1) odd[0] = 1;
        else eve[0] = 1;
        for(int i = 1 ; i < n ; i++) {
            if(arr[i] % 2 == 0) {
                eve[i] = (eve[i-1] + 1)%mod;
                odd[i] = odd[i-1];
            } else {
                eve[i] = odd[i-1];
                odd[i] = (eve[i-1] + 1)%mod;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            ans += odd[i];
            ans %= mod;
        }
        return ans;
    }
};
