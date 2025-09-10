class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> mp;
        for(auto el: items){
            int ID = el[0], score = el[1];
            mp[ID].push(score);
        }
        vector<vector<int>> ans;
        for(auto el: mp) {
            int ID = el.first;
            auto qu = el.second;
            int cnt = 0;
            int su = 0;
            while(1) {
                int elel = qu.top(); qu.pop();
                su += elel;
                cnt++;
                if(cnt >= 5) break;
            }
            ans.push_back({ID, su / 5});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
