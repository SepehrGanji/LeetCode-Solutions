class Solution {
public:
    vector<string> stringSequence(string target) {
        //int ptr = 0;
        int n = target.length();
        vector<string> ans = {};
        for(int ptr = 0 ; ptr < n ; ptr++) {
            string last_str = ans.empty() ? "" : ans.back();
            char current_char = target[ptr];
            char typed_char = 'a';
            while(typed_char <= current_char) {
                ans.push_back(last_str + typed_char);
                typed_char++;
            }
        }
        return ans;
    }
};
