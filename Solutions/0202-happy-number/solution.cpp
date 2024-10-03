class Solution {
public:
    long long sum_digits(int n) {
        long long ans = 0;
        while(n > 0) {
            int dig = n % 10; n /= 10;
            ans += dig * dig;
        }
        return ans;
    }

    bool isHappy(int n) {
        map<long long, bool> mp;
        while(1) {
            int su = sum_digits(n);
            if(su == 1) return true;
            if(mp[su] == true) return false;
            mp[su] = true;
            n = su;
        }    
    }
};
