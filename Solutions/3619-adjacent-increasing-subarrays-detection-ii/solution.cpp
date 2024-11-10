class Solution {
public:
    bool feas(vector<int>& nums, int k) {
        int n = nums.size();
        if (2 * k > n) {
            return false;
        }
    
        int increasing_lengths[n];
        increasing_lengths[n - 1] = 1; 
    
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                increasing_lengths[i] = increasing_lengths[i + 1] + 1;
            } else {
                increasing_lengths[i] = 1;
            }
        }
        for (int i = 0; i <= n - 2 * k; i++) {
            if (increasing_lengths[i] >= k && increasing_lengths[i + k] >= k) {
                return true;
            }
        }
    
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int l = 1, r = (nums.size()/2) + 1;
        while(l < r) {
            int mid = (l+r) / 2;
            //cout << l << ',' << r << ',' << mid << endl;
            cout << "mid: " << mid << ": " << feas(nums, mid) << endl;
            if(feas(nums, mid)) l = mid+1;
            else r = mid;
        }
        return l-1;
    }
};
