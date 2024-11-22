class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void helper(vector<int>& candidates, int target, int i) {
        if(i == candidates.size()) {
            if(target == 0) ans.push_back(tmp);
            return;
        }
        if(candidates[i] <= target) {
            tmp.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i);
            tmp.pop_back();
        }
        helper(candidates, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0);
        return ans;
    }
};
