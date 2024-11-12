class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> mp; // maps price to beauty, only stores the highest beauty for each price!
        set<int> st; // Stores unique prices
        int n = items.size();
        for(int i = 0 ; i < n ; i++) {
            int price = items[i][0];
            int beauty = items[i][1];
            mp[price] = max(beauty, mp[price]);
            st.insert(price);
        }
        int prev_val = -1;
        for(auto it = mp.begin() ; it != mp.end(); it++) {
            int key = it->first, value = it->second;
            int new_val = max(prev_val, value);
            prev_val = new_val;
            mp[key] = new_val;
        }
        vector<int> ans; 
        for(auto q: queries) {
            auto el = st.lower_bound(q); // find the lower_bound of query
            int current_ans = 0;
            if(el == st.end()) {
                // all prices are less than query
                current_ans = mp[*st.rbegin()];
            } else {
                if(el == st.begin()) {
                    if((*el) <= q) {
                        current_ans = mp[*st.begin()];
                    }
                } else {
                    if((*el) > q) {
                        el--;
                    }
                    current_ans = mp[*el];
                }
            }
            ans.push_back(current_ans);
        }
        return ans;
    }
};
