class Solution {
public:
    bool sorted(vector<int>& nums) {
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        if(sorted(nums)) return 0;
        vector<int> arr = nums;
        int n = nums.size();
        sort(arr.begin(), arr.end());
        int i = 0, j = n-1;
        while(arr[i] == nums[i]) i++;
        while(arr[j] == nums[j]) j--;
        return j-i+1;
    }
};
