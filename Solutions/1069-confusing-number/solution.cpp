class Solution {
public:
    bool confusingNumber(int n) {
        set<int> ss = {2, 3, 4, 5, 7};
        map<int, int> mp;
        mp[0] = 0;
        mp[1] = 1;
        mp[6] = 9;
        mp[8] = 8;
        mp[9] = 6;
        int en = 0;
        int bn = n;
        while(n > 0) {
            int d = n % 10; n /= 10;
            if(ss.find(d) != ss.end()) return false;
            en *= 10;
            en += mp[d];
        }
        return bn != en;
    }
};
