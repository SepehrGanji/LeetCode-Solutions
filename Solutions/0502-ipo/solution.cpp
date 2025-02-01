class Solution {
public:
    typedef pair<int, int> pii;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pii> arr;
        int n = profits.size();
        for(int i = 0 ; i < n ; i++) arr.push_back({capital[i], profits[i]});
        sort(arr.begin(), arr.end());
        int ptr = 0, ans = 0;
        while(ptr < n) {
            auto el = arr[ptr];
            int cap = el.first, prof = el.second;
            if(w >= cap) {
                ptr++;
                pq.push(prof);
            } else {
                break;
            }
        }
        while(k--) {
            if(pq.empty()) break;
            int a = pq.top(); pq.pop();
            w += a;
            ans += a;
            while(ptr < n) {
                auto el = arr[ptr];
                int cap = el.first, prof = el.second;
                if(w >= cap) {
                    ptr++;
                    pq.push(prof);
                } else {
                    break;
                }
            }
        }
        return w;
    }
};
