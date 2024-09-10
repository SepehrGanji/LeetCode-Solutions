class Solution {
public:
map<int, int> mp;
int maxi = 0;

bool isFeas(int h) {
    int cnt = 0;
    for(int i = h; i <= maxi ; i++) cnt += mp[i];
    return cnt >= h; 
}
    int hIndex(vector<int>& citations) {
    for(auto el: citations) {
        mp[el]++;
        maxi = max(maxi, el);
    }
    int l = 0, r = maxi;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(isFeas(mid)) l = mid+1;
        else r = mid-1;
    }
    return l-1;
}
};
