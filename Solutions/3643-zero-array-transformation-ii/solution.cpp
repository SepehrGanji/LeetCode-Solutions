class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> arr(n+10, 0);
        for(int i = 0 ; i < k ; i++) {
            auto q = queries[i];
            int l = q[0], r = q[1];
            arr[l] += q[2];
            arr[r+1] -= q[2];
        }
        int op = 0;
        for(int i = 0 ; i < n ; i++) {
            op += arr[i];
            if(op < nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size() + 1;
        while(l < r) {
            int mid = (l+r)/2;
            if(isZeroArray(nums, queries, mid)) r = mid;
            else l = mid+1;
        }
        return r <= queries.size() ? r : -1;
    }
};
