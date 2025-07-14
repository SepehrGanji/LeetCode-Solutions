class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i = 0 ; i < n ; ) {
            int s = intervals[i][0], e = intervals[i][1];
            i++;
            while(i < n && intervals[i][0] <= e) {
                e = max(intervals[i][1], e);
                i++;
            }
            vector<int> veve = {s, e};
            ans.push_back(veve);
        }
        return ans;
    }
};
