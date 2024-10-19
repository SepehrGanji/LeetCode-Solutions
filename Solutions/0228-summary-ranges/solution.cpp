class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans; int n = nums.size();
        if(n == 0) return ans;
        int start = nums[0], end = nums[0];
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] == end+1) end = nums[i];
            else {
                //push to ans
                if(start == end) {
                    ans.push_back(to_string(start));
                } else {
                    string mmd = "";
                    mmd += to_string(start);
                    mmd += "->";
                    mmd += to_string(end);
                    ans.push_back(mmd);
                }
                start = nums[i], end = nums[i];
            }
        }
        if(start == end) {
            ans.push_back(to_string(start));
        } else {
            string mmd = "";
            mmd += to_string(start);
            mmd += "->";
            mmd += to_string(end);
            ans.push_back(mmd);
        }
        return ans;
    }
};
