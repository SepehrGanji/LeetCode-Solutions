class Solution {
public:
    int calc(int n) {
        vector<int> digs;
        while(n > 0) {
            digs.push_back(n % 10);
            n /= 10;
        }
        int ans = 0;
        int k = digs.size();
        for(auto el: digs) {
            ans += pow(el, k);
        }
        return ans;
    }

    bool isArmstrong(int n) {
        return calc(n) == n;    
    }
};
