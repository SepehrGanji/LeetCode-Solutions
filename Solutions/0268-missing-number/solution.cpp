class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n+1)) / 2;
        int arr_sum = 0;
        for(auto el: nums) arr_sum += el;
        return sum - arr_sum;
    }
};
