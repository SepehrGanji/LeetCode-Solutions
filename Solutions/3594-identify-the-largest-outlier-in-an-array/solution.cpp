class Solution {
public:
    int n, sum;

    bool valid(vector<int>& nums, int outIdx) {
        int l = 0, r = n;
        while(l < r) {
            int mid = (l+r)/2;
            if(mid == outIdx) {
                r--;
                continue;
            }
            int local_sum = sum - nums[outIdx];
            if(local_sum == 2 * nums[mid]) return true;
            else if(local_sum < 2 * nums[mid]) r = mid;
            else l = mid+1;
        }
        return false;
    }

    bool valid2(vector<int>& nums, int outIdx) {
        int l = 0, r = n;
        while(l < r) {
            int mid = (l+r)/2;
            if(mid == outIdx) {
                l++;
                continue;
            }
            int local_sum = sum - nums[outIdx];
            if(local_sum == 2 * nums[mid]) return true;
            else if(local_sum < 2 * nums[mid]) r = mid;
            else l = mid+1;
        }
        return false;
    }

    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        for(int i = 0; i < n ; i++) sum += nums[i];
        for(int i = n - 1 ; i >= 0 ; i--)
            if(valid(nums, i) || valid2(nums, i)) return nums[i];
        return -1;
    }
};
