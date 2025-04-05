class Solution {
public:
    void generateSubsets(const vector<int>& nums, int index, vector<int> subset,
                         vector<vector<int>>& subsets) {
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        generateSubsets(nums, index + 1, subset, subsets);
        subset.pop_back();
        generateSubsets(nums, index + 1, subset, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        generateSubsets(nums, 0, {}, subsets);
        int ans = 0;
        for(auto st: subsets) {
            int local_ans = 0;
            for(int num: st) local_ans ^= num;
            ans += local_ans;
        }
        return ans;
    }
};
