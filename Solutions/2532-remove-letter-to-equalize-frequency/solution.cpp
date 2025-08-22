class Solution {
public:
    bool poss(string word) {
        map<char, int> mp;
        int frq = -1;
        for(auto el: word) mp[el]++;
        for(auto el: mp) {
            if(el.second != 0) {
                if(frq == -1) frq = el.second;
                else if(frq != el.second) return false; 
            }
        }
        return true;
    }

    bool equalFrequency(string word) {
        string sofar = "";
        for(int i = 0 ; i < word.length() ; i++) {
            string local = sofar + word.substr(i+1);
            if(poss(local)) return true;
            sofar += word[i];
        }
        return false;
    }
};
