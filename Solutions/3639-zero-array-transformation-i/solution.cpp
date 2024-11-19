class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n+10, 0);
        for(auto q: queries) {
            int l = q[0], r = q[1];
            arr[l]++;
            arr[r+1]--;
        }
        int op = 0;
        for(int i = 0 ; i < n ; i++) {
            op += arr[i];
            if(op < nums[i]) return false;
        }
        return true;
    }
};
