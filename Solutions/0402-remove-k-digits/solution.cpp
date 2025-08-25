class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto el: num) {
            while(!st.empty() && k > 0 && st.top() > el) {
                st.pop();
                k--;
            }
            st.push(el);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(k > 0) {
            int x = ans.length() - k;
            ans = ans.substr(0, x);
        }
        bool flg = false;
        string ans2 = "";
        for(auto ch: ans) {
            if(flg == false && ch == '0') continue;
            flg = true;
            ans2 += ch;
        }
        if(ans2 == "") return "0";
        return ans2;
    }
};
