class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int idx = 0, cnt = 0;
        for(int num = 1 ; num <= n && maxSum >= 0 ; num++) {
            if(idx < banned.size() && banned[idx] == num) {
                while(idx < banned.size() && banned[idx] == num) idx++;
            } else {
                maxSum -= num;
                if(maxSum >= 0) cnt++;
            }
        }
        return cnt;
    }
};
