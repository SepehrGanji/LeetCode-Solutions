class Solution {
public:
    string solve(string s, int k) {
        string a, b;
        //reverse the first k
        for(int i = k ; i >= 0 ; i--) {
            a += s[i];
        }
        for(int i = k+1 ; i < s.length() ; i++) {
            a += s[i];
        }
        // reverse the last k
        int n = s.size();
        for(int i = 0 ; i < n-1-k ; i++) {
            b += s[i];
        }
        for(int i = n-1 ; i >= n-1-k ; i--) {
            b += s[i];
        }
        return min(a, b);
    }
    
    string lexSmallest(string s) {
        string ans = solve(s, 0);
        for(int i = 1 ; i < s.length() ; i++) {
            ans = min(ans, solve(s, i));
        }
        return ans;
    }
};
