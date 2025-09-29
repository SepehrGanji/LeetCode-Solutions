class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        auto arz = arrays[0];
        int mini = 1000000;
        int maxi = -1000000;
        int ans = 0;
        for(auto arr: arrays) {
            int local_mini = arr[0];
            ans = max(ans, maxi - local_mini);
            int local_maxi = arr[arr.size() - 1];
            ans = max(ans, local_maxi- mini);
            mini = min(mini, local_mini);
            maxi = max(maxi, local_maxi);
        }
        return ans;
    }
};
