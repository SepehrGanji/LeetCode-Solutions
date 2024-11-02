class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        bool dp[n][2]; //0 odd, 1 even
        dp[n-1][0] = dp[n-1][1] = true;
        map<int, int> idxmap;
        set<int> st;
        idxmap[arr[n-1]] = n-1;
        st.insert(arr[n-1]);
        //
        for(int i = n - 2 ; i >= 0 ; i--) {
            auto self_it = st.find(arr[i]);
            bool found = (self_it != st.end());
            // Calculate the odd
            if(found) {
                int idx = idxmap[arr[i]];
                dp[i][0] = dp[idx][1];
            } else {
                auto up = st.upper_bound(arr[i]);
                if(up == st.end()) {
                    // Screwed!
                    dp[i][0] = false;
                } else {
                    // Oh found it!
                    int idx = idxmap[*up];
                    dp[i][0] = dp[idx][1];
                }
            }
            
            // Calculate the even
            if(found) {
                int idx = idxmap[arr[i]];
                dp[i][1] = dp[idx][0];
            } else {
                auto up = st.lower_bound(arr[i]);
                if(up == st.begin()) {
                    dp[i][1] = false;
                } else {
                    // *it--;
                    up--;
                    int idx = idxmap[*up];
                    dp[i][1] = dp[idx][0];
                }
            }
            // Update the set and map
            st.insert(arr[i]);
            idxmap[arr[i]] = i;
        }
        
        // Ans is equal to number of trues in odd jumps...
        int ans = 0;
        for(int i = 0 ; i < n ; i++) if(dp[i][0]) ans++;
        return ans;
    }
};
