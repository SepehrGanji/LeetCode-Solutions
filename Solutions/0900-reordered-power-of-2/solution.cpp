class Solution {
public:
    string magic(long n) {
        string ans = "";
        while(n > 0) {
            int c = n % 10;
            n /= 10;
            ans += ('0' + c);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    bool reorderedPowerOf2(int n) {
        if(n == 1) return true;
        vector<string> lst;
        long num = 2;
        for(int i = 1 ; i <= 30 ; i++) {
            lst.push_back(magic(num));
            num *= 2;
        }
        string mag = magic(n);
        for(auto el: lst) {
            if(mag == el) return true;
        }
        return false;
    }
};

