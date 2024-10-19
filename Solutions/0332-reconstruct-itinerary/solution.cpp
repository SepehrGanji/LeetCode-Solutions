class Solution {
public:
    vector<string> ans;
    unordered_map<string, vector<string>> mp;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ti: tickets) {
            string src = ti[0], des = ti[1];
            // if(mp.find(src) == mp.end()) mp[src] = {};
            mp[src].push_back(des); 
        }
        for(auto el: mp) {
            auto vc = el.second;
            sort(vc.begin(), vc.end(), greater<>());
            mp[el.first] = vc;
        }
        // for(auto el: mp) {
        //     cout << el.first << ':';
        //     for(auto mmd: el.second) cout << mmd << ' ';
        //     cout << endl;
        // }
        DFS("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void DFS(string origin) {
        // cout << origin << endl;
        // try {
        //     if(mp.find(origin) != mp.end()) {
        //         auto vc = mp[origin];
        //         while(!vc.empty()) {
        //             string next_dest = vc.back();
        //             vc.pop_back();
        //             DFS(next_dest);
        //         }
        //     }
        // } catch(int e) {
        //     cerr << origin << endl;
        // }
        while(!mp[origin].empty()) {
            string next = mp[origin].back();
            mp[origin].pop_back();
            DFS(next);
        }
        
        ans.push_back(origin);
    }
};
