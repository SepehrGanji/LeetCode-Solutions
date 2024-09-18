class Solution {
    typedef pair<int, int> pii;
typedef pair<int, pii> pomad;
public:
    bool find_el(vector<int>& nums, int l, int el) {
    int r = nums.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(nums[mid] == el) return true;
        else if(nums[mid] < el) l = mid+1;
        else r = mid-1;
    }
    return false;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<pomad> ans;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            int el = 0 - (nums[i] + nums[j]);
            if(find_el(nums, j+1, el)) ans.insert({nums[i], pii(nums[j], el)});
        }
    }
    vector<vector<int>> real_ans;
    for(auto tri: ans) {
        real_ans.push_back({tri.first, tri.second.first, tri.second.second});
    }
    return real_ans;
}
};
