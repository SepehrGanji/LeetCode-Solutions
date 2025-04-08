class Solution {
public:
    bool isD(int idx, vector<int>& nums) {
        int n = nums.size();
        if(idx >= n) return true;
        set<int> st;
        for(int i = idx ; i < n ; i++) {
            int el = nums[i];
            if(st.find(el) != st.end()) return false;
            st.insert(el);
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        while(i < nums.size()) {
            if(isD(i, nums)) return ans;
            ans++;
            i += 3;
        }
        return ans;
    }
};
