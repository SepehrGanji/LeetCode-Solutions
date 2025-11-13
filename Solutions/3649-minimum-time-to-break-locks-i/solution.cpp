class Solution {
public:
    
    int findMinimumTime(vector<int>& arr, int k) {
        int ans = INT_MAX;
        sort(arr.begin(), arr.end());
        do {
            float x = 1;
            int local_ans = 0;
            for (int el : arr) {
                int n = ceil(el / x);
                local_ans += n;
                x += k; 
            }
            ans = min(ans, local_ans);
        } while (next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};

