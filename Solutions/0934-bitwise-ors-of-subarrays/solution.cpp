class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cur;
        cur.insert(0);
        for(auto el: arr) {
            unordered_set<int> cur2;
            for(auto el2: cur) cur2.insert(el | el2);
            cur2.insert(el);
            cur = cur2;
            for(auto el2: cur) ans.insert(el2);
        }
        return ans.size();
    }
};
