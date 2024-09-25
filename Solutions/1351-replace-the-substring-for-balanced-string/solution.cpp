class Solution {
public:
map<char, int> IDX;
    
bool isValid(string &s, map<char, int> &red, int cnt[4][100010], int l, int r) {
    l++, r++;
    for(auto pi: red) {
        if(cnt[IDX[pi.first]][r] - cnt[IDX[pi.first]][l-1] < pi.second) return false;
    }
    return true;
}

int balancedString(string s) {
    IDX['Q'] = 0; IDX['W'] = 1; 
    IDX['E'] = 2; IDX['R'] = 3; 
    int n = s.length(); int m = n/4;
    map<char, int> mp; map<char, int> red; int cnt[4][100010];
    
    //
    for(auto ch: s) mp[ch]++;
    for(auto p: mp) if(p.second > m) red[p.first] = p.second - m;
    if(red.empty()) return 0;
    for(int i = 0 ; i < 4 ; i++) cnt[i][0] = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < 4 ; j++) cnt[j][i+1] = cnt[j][i];
        cnt[IDX[s[i]]][i+1]++;
    }
    //
    int ans = n;
    for(int const_l = 0 ; const_l < n ; const_l++) {
        int l = const_l, r = n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(isValid(s, red, cnt, const_l, mid)) r = mid-1;
            else l = mid+1;
        }
        //const_l, r+1
        if(isValid(s, red, cnt, const_l, r+1)) ans = min(ans, r-const_l+2);
    }
    return ans;
}
};
