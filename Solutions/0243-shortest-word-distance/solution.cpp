class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> po1, po2;
        
        for(int i = 0 ; i < wordsDict.size() ; i++) {
            string el = wordsDict[i];
            if(el == word1) po1.push_back(i);
            else if(el == word2) po2.push_back(i);
        }
        
        int ans = INT_MAX;
        for(auto el1: po1)
            for(auto el2: po2)
                ans = min(ans, abs(el1-el2));
        return ans;
    }
};
