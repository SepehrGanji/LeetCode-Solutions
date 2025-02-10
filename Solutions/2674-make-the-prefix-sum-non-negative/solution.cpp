class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int n = nums.size();
        vector<long> pfx(n, 0); pfx[0] = nums[0];
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1 ; i < n ; i++) pfx[i] = nums[i] + pfx[i-1];
        int ans = 0, vault = 0;
        for(int i = 0 ; i < n ; i++) {
            pq.push(nums[i]);
            if(pfx[i] + vault < 0) {
                int to = pq.top(); pq.pop();
                vault += (-1 * to);
                ans++;
            }
        }
        return ans;
    }
};
