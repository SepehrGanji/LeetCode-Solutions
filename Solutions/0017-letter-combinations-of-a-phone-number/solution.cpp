class Solution {
public:
    vector<string> ans;

    map<char, vector<char>> mp;

    void mmd(string digits, int i, string sofar) {
        if(i == digits.length()) {
            ans.push_back(sofar);
            return;
        }
        for(auto dig: mp[digits[i]]) {
            mmd(digits, i+1, sofar+dig);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        mmd(digits, 0, "");
        return ans;
    }
};
