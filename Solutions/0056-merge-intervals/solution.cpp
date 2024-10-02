class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for(auto el: intervals) arr.push_back(make_pair(el[0], el[1]));
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back({arr[0].first, arr[0].second});
        for(int i = 1 ; i < arr.size() ; i++) {
            auto curr_el = arr[i];
            int a = curr_el.first, b = curr_el.second;
            auto last_el = ans.back();
            int aa = last_el[0], bb = last_el[1];
            if(a <= bb) {
                ans.pop_back();
                ans.push_back({min(a, aa), max(b, bb)});
            } else {
                ans.push_back({a, b});
            }
        }
        return ans;
    }
};
