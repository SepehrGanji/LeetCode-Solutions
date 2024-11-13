class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> bits;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            bits.clear();
            while (nums[i]) {
                bits.push_back(nums[i] % 2);
                nums[i] /= 2;
            }
            bits.push_back(0);
            for (int j = 1; j < bits.size(); j++) {
                if (!bits[j]) {
                    bits[j - 1] = 0;
                    break;
                }
            }
            for (int j = 0; j < bits.size(); j++) {
                ans[i] += (bits[j] * pow(2, j));
            }
        }
        return ans;
    }
};
