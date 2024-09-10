class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    map<char, int> cnt;
    for(int i = 0 ; i < magazine.size() ; i++) cnt[magazine[i]]++;
    for(int i = 0 ; i < ransomNote.size() ; i++) {
        char c = ransomNote[i];
        cnt[c]--;
        if(cnt[c] < 0) return false;
    }
    return true;
}
};
