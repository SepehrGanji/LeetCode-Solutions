class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1 ; i < strs.size() ; i++) {
            string loca_ans = "";
            for(int j = 0 ; j < strs[i].length() ; j++) {
                if(ans[j] == strs[i][j]) loca_ans += ans[j];
                else break;
            }
            ans = loca_ans;
        }
        return ans;
    }
};
