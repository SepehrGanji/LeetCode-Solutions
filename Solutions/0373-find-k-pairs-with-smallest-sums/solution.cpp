class Solution {
public:
    typedef pair<int, int> pii;
    typedef pair<int, pii> trip;



    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        set<pii> visited;
        priority_queue<trip, vector<trip>, greater<trip>> pq;
        pq.push({nums1[0]+nums2[0], {0, 0}});
        visited.insert({0, 0});
        while(k-- && !pq.empty()) {
            auto top = pq.top(); pq.pop();
            int i = top.second.first, j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});
            if(i+1 < n && visited.find({i+1, j}) == visited.end()) {
                visited.insert({i+1, j});
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
            }
            if(j+1 < m && visited.find({i, j+1}) == visited.end()) {
                visited.insert({i, j+1});
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
            } 
        }
        return ans;
    }
};
