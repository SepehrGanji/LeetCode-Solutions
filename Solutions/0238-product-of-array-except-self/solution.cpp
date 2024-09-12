class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int pfx[n], sfx[n];
    pfx[0] = nums[0], sfx[n-1] = nums[n-1];
    for(int i = 1 ; i < n ; i++) pfx[i] = pfx[i-1] * nums[i];
    for(int i = n-2 ; i >= 0 ; i--) sfx[i] = sfx[i+1] * nums[i];
    vector<int> ans;
    ans.push_back(sfx[1]);
    for(int i = 1 ; i < n-1 ; i++) ans.push_back(pfx[i-1] * sfx[i+1]);
    ans.push_back(pfx[n-2]);
    return ans;
}
};
