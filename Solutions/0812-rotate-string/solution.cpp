class Solution {
public:
    bool canDo(string a, string b, int j) {
        int n = a.length();
        int i = 0;
        while(i < n) {
            if(j >= n) j %= n;
            if(a[i] != b[j]) break;
            i++, j++;
        }
        return i == n;
    }
    
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();
        if(n != m) return false;
        string ss = s, gg = goal;
        sort(ss.begin(), ss.end());
        sort(gg.begin(), gg.end());
        if(ss != gg) return false;
        // it is possible
        int i = 0;
        int ch = s[i];
        for(int j = 0 ; j < n ; j++) {
            if(ch == goal[j] && canDo(s, goal, j)) return true;
        }
        return false;
    }
};
