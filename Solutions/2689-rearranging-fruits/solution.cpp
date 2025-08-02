class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        map<int, int> mp;
        for(auto el: basket1) mp[el]++;
        for(auto el: basket2) mp[el]++;
        for(auto el: mp) if(el.second % 2 == 1) return -1;
        // building nokhake arrays
        vector<int> n1, n2;
        map<int, int> mpp;
        for(auto el: mp) mp[el.first] = el.second/2;
        for(auto el: basket1) mpp[el]++;
        for(auto el: mpp) {
            int num = el.first, cnt = el.second;
            int diff = cnt - mp[num];
            if(diff <= 0) continue;
            while(diff--) n1.push_back(num);
        }
        mpp.clear();
        for(auto el: basket2) mpp[el]++;
        for(auto el: mpp) {
            int num = el.first, cnt = el.second;
            int diff = cnt - mp[num];
            if(diff <= 0) continue;
            while(diff--) n2.push_back(num);
        }
        // int n = basket1.size();
        // we have the nokhale arrays
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());
        int min_cost = 2 * min(basket1[0], basket2[0]);
        int n = n1.size();
        for(int i = 0 ; i < n ; i++) {
            int j = n-1-i;
            ans += min(min_cost, min(n1[i], n2[j]));
        }
        return ans;
    }
};
