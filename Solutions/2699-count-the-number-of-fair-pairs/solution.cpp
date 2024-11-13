class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            int el = nums[i];
            int target, l, r;
            //cout << "El is: " << el << endl;
            // bin_search for the first number that is more than or eq
            target = lower - el;
            l = i+1, r = n-1;
            //cout << "1Searching for target: " << target << endl;
            while(l < r) {
                int mid = (l+r)/2;
                if(nums[mid] >= target) r = mid;
                else l = mid + 1;
            }
            if(nums[r] < target) continue;
            int bibi = r;
            //cout << "bibi, is: " << bibi << endl;
            // bin_search for the last number that is less than or eq
            target = upper - el;
            l = i+1, r = n-1;
            //cout << "2Searching for target: " << target << endl;
            while(l < r) {
                int mid = ceil((l+r)/2.0);
                if(nums[mid] <= target) l = mid;
                else r = mid-1;
            }
            if(l >= n || nums[l] > target) continue;
            //cout << "l, is: " << l << endl;
            ans += (l-bibi+1);
        }
        return ans;
    }
};
