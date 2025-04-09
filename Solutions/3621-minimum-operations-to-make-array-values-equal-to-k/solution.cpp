class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for(auto el: nums) st.insert(el);
        int beg = *st.begin();
        if(beg < k) return -1;
        int ans = st.size();
        for(auto el: st) {
            if(el > k) return ans;
            ans--;
        }
        return 0;
    }
};
