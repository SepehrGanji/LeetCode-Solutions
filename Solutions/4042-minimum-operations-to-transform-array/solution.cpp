class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 1;
        int n = nums1.size();
        int x = nums2[n];
        int min_so_far = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            int el1 = min(nums1[i], nums2[i]);
            int el2 = max(nums1[i], nums2[i]);
            ans += el2-el1;
            if(x <= el1) {
                min_so_far = min (min_so_far, el1-x);
            } else if(x >= el2) {
                min_so_far = min (min_so_far, x-el2);
            } else {
                min_so_far = 0;
            }
        }
        return ans+min_so_far;
    }
};
