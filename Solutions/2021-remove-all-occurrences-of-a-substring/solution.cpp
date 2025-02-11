class Solution {
public:
    bool match(stack<char>& stk, string &part, int plen) {
        stack<char> tmp = stk;
        for(int i = plen - 1 ; i >= 0 ; i--) {
            if(tmp.top() != part[i]) return false;
            tmp.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int n = s.length();
        int m = part.length();

        for(int i = 0 ; i < n ; i++) {
            stk.push(s[i]);
            if(stk.size() >= m && match(stk, part, m)) {
                for(int j = 0 ; j < m ; j++) stk.pop();
            }
        }

        string ans = "";
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
