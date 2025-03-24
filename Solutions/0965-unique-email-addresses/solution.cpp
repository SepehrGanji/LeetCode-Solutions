class Solution {
public:
    string filter(string s) {
        string ans = "";
        int i = 0;
        bool bad = false;
        for( ; s[i] != '@' ; i++){
            if(bad) continue;
            else {
                if(s[i] == '+') bad = true;
                else {
                    if(s[i] != '.') ans += s[i];
                }
            }
        }
        while(i < s.length()) ans += s[i++];
        return ans;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto em: emails) st.insert(filter(em));    
        return st.size();
    }
};
