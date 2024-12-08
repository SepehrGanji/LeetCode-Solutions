class Solution {
public:
    typedef pair<int, int> pii;

    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        int maxVal = 0;
        int ans = 0;
        sort(events.begin(), events.end());
        for(int i = 0 ; i < events.size() ; i++) {
            int start = events[i][0], end = events[i][1], val = events[i][2];
            while(!pq.empty()) {
                auto el = pq.top();
                if(el.first >= start) break;
                pq.pop();
                maxVal = max(maxVal, el.second);
            }
            ans = max(ans, val+maxVal);
            pq.push(pii(end, val));
        }
        return ans;
    }
};
