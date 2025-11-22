class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int t = 0, n = order.size();
        set<int> st;
        st.insert(0);
        st.insert(n+1);
        long long cnt = 0;
        while(t < n) {
            int el = order[t] + 1;
            auto lo = st.lower_bound(el);
            --lo;
            auto hi = st.upper_bound(el);
            long long left_cnt = el - (*lo);
            long long right_cnt = (*hi) - el;
            cnt += (left_cnt * right_cnt);
            st.insert(el);
            if(cnt >= k) break;
            t++;
        }

        if(t == n) return -1;
        return t;
    }
};
