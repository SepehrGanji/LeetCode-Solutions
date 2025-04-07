class Solution {
public:
    int gcd(int a, int b) {
        if(b==0)
           return a;
        else
           return gcd(b, a%b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(auto num: deck) mp[num]++;
        vector<int> cnts;
        for(auto pai: mp) cnts.push_back(pai.second);
        if(cnts.size() == 1) {
            return cnts[0] > 1;
        }
        int ggg = gcd(max(cnts[0], cnts[1]), min(cnts[0], cnts[1]));
        for(int i = 2 ; i < cnts.size() ; i++) {
            int cur = cnts[i];
            int maxi = max(ggg, cur);
            int mini = min(ggg, cur);
            ggg = gcd(maxi, mini);
        }
        return ggg > 1;
    }
};
