class Solution {
public:
    vector<int> arr;
    
    bool found(int i, int j) {
        for(auto el: arr) if(el >= i && el < j) return true;
        return false;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++) if(nums[i] >= nums[i+1]) arr.push_back(i);
        for(int i = 0 ; i+k-1 < n ; i++) {
            int j = i+k-1;
            if(nums[j] - nums[i] + 1 == k) {
                // potential
                if(!found(i, j)) {
                    ans.push_back(nums[j]);
                    continue;
                }
            }
            ans.push_back(-1);
        }
        return ans;
    }
};
