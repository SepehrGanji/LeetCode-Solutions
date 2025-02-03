class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        set<int> st;
        map<int, int> mp;
        // initial window
        for(int i = 0 ; i < k ; i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
            }
            mp[nums[i]]++;
        }
        ans.push_back(st.size());
        // shifting the window
        for(int i = k ; i < n ; i++) {
            int el1 = nums[i-k], el2 = nums[i];
            if(el1 != el2) {
                // remove el1
                mp[el1]--;
                if(mp[el1] <= 0) st.erase(el1);
                if(st.find(el2) == st.end()) {
                    st.insert(el2);
                }
                mp[el2]++;
            }
            ans.push_back(st.size());
        }
        return ans;
    }
};
