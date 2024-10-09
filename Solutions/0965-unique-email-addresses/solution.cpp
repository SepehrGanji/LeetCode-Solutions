class Solution {
public:
    string separate_email(string email) {
        string local_name = "", domain_name = "";
        int ptr = 0, n = email.length();
        bool ignore = false;
        while(email[ptr] != '@') {
            if(!ignore) {
                int ch = email[ptr];
                if(ch == '+') ignore = true;
                else if(ch != '.') local_name += ch;
            }
            ptr++;
        }
        ptr++;
        while(ptr < n) {
            domain_name += email[ptr];
            ptr++;
        }
        
        return local_name + "@" + domain_name;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto email: emails) {
            string ans = separate_email(email);
            st.insert(ans);
        }
        return st.size();
    }
};
