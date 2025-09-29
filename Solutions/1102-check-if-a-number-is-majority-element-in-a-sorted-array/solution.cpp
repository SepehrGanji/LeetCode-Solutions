class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int mcq = nums.size() / 2;
        int cnt = 0;
        for(auto el: nums) if(el == target) cnt++;
        return cnt > mcq;
    }
};
