class Solution {
public:
    int inc(vector<int>& arr) {
        int ans = 1, local_ans = 1;
        for(int i = 1 ; i < arr.size() ; i++) {
            if(arr[i] > arr[i-1]) {
                local_ans++;
                ans = max(ans, local_ans);
            } else local_ans = 1;
        }
        return ans;
    }

    int dec(vector<int>& arr) {
        int ans = 1, local_ans = 1;
        for(int i = 1 ; i < arr.size() ; i++) {
            if(arr[i] < arr[i-1]) {
                local_ans++;
                ans = max(ans, local_ans);
            } else local_ans = 1;
        }
        return ans;
    } 

    int longestMonotonicSubarray(vector<int>& nums) {
        return max(inc(nums), dec(nums));
    }
};
