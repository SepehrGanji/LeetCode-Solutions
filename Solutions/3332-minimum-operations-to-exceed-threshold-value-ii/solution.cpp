class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for(auto num: nums) pq.push(num);
        int ans = 0;
        while(1) {
            if(pq.top() >= k) break;
            long min1 = pq.top(); pq.pop();
            long min2 = pq.top(); pq.pop();
            long new_num = (min1*2) + min2;
            pq.push(new_num);
            ans++;
        }
        return ans;
    }
};
