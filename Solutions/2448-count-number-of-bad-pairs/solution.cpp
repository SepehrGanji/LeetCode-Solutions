class Solution {
public:
    long long kchoose2(long long k) {
        return ((k) * (k-1))/2;
    }

    long long countBadPairs(vector<int>& nums) {
        map<int, int> mp; int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            int diff = nums[i] - i;
            mp[diff]++;
        }
        long long all = 0, good = 0;
        all = kchoose2(n);
        for(auto el: mp) {
            int cnt = el.second;
            good += kchoose2(cnt);
        }
        return all-good;
    }
};
