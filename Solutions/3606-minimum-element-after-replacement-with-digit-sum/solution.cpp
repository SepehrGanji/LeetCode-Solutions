class Solution {
public:
    int digSum(int a) {
        int ans = 0;
        while(a > 0) {
            ans += a%10;
            a /= 10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto num: nums) {
            ans = min(ans, digSum(num));
        }
        return ans;
    }
};
