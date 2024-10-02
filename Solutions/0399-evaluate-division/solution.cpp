class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    map<string, vector<pair<string, double>> > g;
    int n = equations.size();
    for(int i = 0 ; i < n ; i++) {
        auto eq = equations[i];
        double val = values[i];
        string a = eq[0], b = eq[1];
        // do the a
        if(g.find(a) == g.end()) g[a] = {};
        g[a].push_back(make_pair(b, val));
        // do the b
        if(g.find(b) == g.end()) g[b] = {};
        g[b].push_back(make_pair(a, 1.0/val));
    }
    vector<double> ans;
    for(auto q: queries) {
        string a = q[0], b = q[1];
        double vv = 1;
        if(g.find(a) == g.end() || g.find(b) == g.end()) vv = -1;
        else if(a != b) {
            stack<pair<string, double>> qq;
            map<string, bool> seen;
            qq.push(make_pair(a, 1.0));
            while(1) {
                if(qq.empty()) {
                    vv = -1;
                    break;
                }
                auto full_el = qq.top(); qq.pop();
                string el = full_el.first; double el_val = full_el.second;
                if(seen[el]) continue;
                seen[el] = true;
                //cout << "el: " << el << " elval:" << el_val << endl;
                if(el == b) {
                    vv = el_val;
                    break;
                }
                for(auto nei: g[el]) {
                    qq.push(make_pair(nei.first, el_val * nei.second));
                }
            }
        }
        ans.push_back(vv);
    }
    // for(auto mmd: ans) {
    //     cout << mmd << ' ';
    // }
    // cout << endl;
    return ans;
}
};
