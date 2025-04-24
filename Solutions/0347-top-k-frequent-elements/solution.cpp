class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto num: nums) cnt[num]++;
        priority_queue<pair<int, int>> pq;
        for(auto el: cnt) pq.push({el.second, el.first});
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
