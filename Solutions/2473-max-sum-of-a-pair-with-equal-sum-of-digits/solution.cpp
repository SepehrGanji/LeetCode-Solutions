class Solution {
public:
    int digSum(int n) {
        int ans = 0;
        while(n > 0){
            ans += (n % 10);
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        map<int, int> mp;
        int ans = -1;
        for(auto num: nums) {
            int di = digSum(num);
            if(mp.find(di) != mp.end()) {
                ans = max(ans, num + mp[di]);
                mp[di] = max(mp[di], num);
            } else mp[di] = num;
        }
        return ans;
    }
};
