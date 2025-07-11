class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 1;
        priority_queue<int,vector<int>,greater<int> >pq;
        pq.push(intervals[0][1]);
        for(int i = 1 ; i < intervals.size(); i++) {
            int s = intervals[i][0], e = intervals[i][1];
            if(s < pq.top()) {
                pq.push(e);
                int a = pq.size();
                ans = max(ans, a);
            } else {
                pq.pop();
                pq.push(e);
            }
        }
        return ans;
    }
};
