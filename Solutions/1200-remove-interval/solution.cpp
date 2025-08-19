class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int rma = toBeRemoved[0];
        int rmb = toBeRemoved[1];
        for(auto el: intervals) {
            int a = el[0], b = el[1];
            if(a > rmb || b < rma) {
                // outside, just include
                ans.push_back({a, b});
            } else {
                // inside, see if complete or partial
                if(a >= rma && b <= rmb) continue;
                // partially inside
                if(a < rma) ans.push_back({a, rma});
                if(b > rmb) ans.push_back({rmb, b});
            }
        }
        return ans;
    }
};
