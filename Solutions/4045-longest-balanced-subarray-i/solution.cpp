class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            set<int> odds;
            set<int> evens;
            for(int j = i ; j < n ; j++) {
                if(nums[j] % 2 == 0) evens.insert(nums[j]);
                else odds.insert(nums[j]);
                if(evens.size() == odds.size()) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
