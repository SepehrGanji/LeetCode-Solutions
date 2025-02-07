class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        set<int> st;
        map<int, int> colmp;
        map<int, int> ballmp;
        for(auto q: queries) {
            int ball = q[0], color = q[1];
            if(ballmp.find(ball) != ballmp.end()) {
                // remove color first
                int old_col = ballmp[ball];
                colmp[old_col]--;
                if(colmp[old_col] <= 0) st.erase(old_col);
            }
            // do the coloring
            ballmp[ball] = color;
            colmp[color]++;
            st.insert(color);
            ans.push_back(st.size());
        }
        return ans;
    }
};
