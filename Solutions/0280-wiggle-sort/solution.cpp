class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int pk = n-1;
        int i = 0;
        
        while(i < pk) {
            ans.push_back(nums[i]);
            ans.push_back(nums[pk]);
            // ans.push_back(nums[i+1]);
            i++;
            pk--;
        }
        if(i == pk) ans.push_back(nums[i]);
        for(int i = 0 ; i < n ; i++) nums[i] = ans[i];
    }
};
