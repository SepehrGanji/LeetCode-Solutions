class Solution {
public:
    map<int, int> mp;
    
    string rep(string s, int times) {
        string ans = "";
        while(times--) ans += s;
        return ans;
    }
    
    string proc(string s, int start, int end) {
        string ans = "";
        for(int i = start ; i < end ;) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9') {
                    num *= 10;
                    num += (s[i] - '0');
                    i++;
                }
                int j = mp[i];
                string local = proc(s, i+1, j);
                ans += rep(local, num);
                i = j+1;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
    
    string decodeString(string s) {
        stack<int> st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '[') {
                st.push(i);
            } else if(s[i] == ']') {
                int ai = st.top(); st.pop();
                mp[ai] = i;
            }
        }
        
        return proc(s, 0, n);
    }
};
