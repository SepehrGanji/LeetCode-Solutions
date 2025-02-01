class Solution {
public:
    typedef pair<int, int> pii;
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> pfx(n, 0);
        vector<int> sfx(n, 0);
        int ans = startTime[0] - 0;
        pfx[0] = ans;
        for(int i = 1 ; i < n ; i++) {
            int gap = startTime[i] - endTime[i-1];
            ans = max(ans, gap);
            pfx[i] = max(gap, pfx[i-1]);
        }
        sfx[n-1] = eventTime - endTime[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            int gap = startTime[i+1] - endTime[i];
            sfx[i] = max(gap, sfx[i+1]);
        }
        // delete the first one
        int len = endTime[0] - startTime[0];
        int new_gap = startTime[1] - 0;
        if(sfx[1] >= len) {
            ans = max(ans, new_gap);
        } else {
            ans = max(ans, startTime[1] - len);
        }
        // delete the last one
        len = endTime[n-1] - startTime[n-1];
        new_gap = eventTime - endTime[n-2];
        if(pfx[n-2] >= len) {
            ans = max(ans, new_gap);
        } else {
            ans = max(ans, eventTime - (endTime[n-2] + len));
        }
        // delete between
        for(int i = 1 ; i < n-1 ; i++) {
            int len = endTime[i] - startTime[i];
            int new_gap = startTime[i+1] - endTime[i-1];
            if(pfx[i-1] >= len || sfx[i+1] >= len) {
                ans = max(ans, new_gap);
            } else {
                // chasb be right
                ans = max(ans, (startTime[i+1]-len) - endTime[i-1]);
                // casb be left
                ans = max(ans, startTime[i+1] - (endTime[i-1]+len));
            }
        }
        return ans;
    }
};
