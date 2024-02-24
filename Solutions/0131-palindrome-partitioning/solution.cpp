class Solution {
public:
    bool isPalindrome(string s) {
  int n = s.length();
  if(n <= 1) return true;
  int i = 0, j = n - 1;
  while(i < j) 
    if(s[i++] != s[j--]) return false;
  return true;
}

string till_end(string s, int i) {
  string rem = "";
  for(int j = i + 1 ; j < s.length() ; j++) 
    rem += s[j];
  
  return rem;
}

vector<vector<string>> partition(string s) {
  if(s.length() == 0) return {{}};
  if(s.length() == 1) {
    string mamad = "";
    mamad += s[0];
    return {{mamad}};
  }
  string s1 = "";
  vector<vector<string>> ans;
  for(int i = 0 ; i < s.length() ; i++) {
    s1 += s[i];
    if(isPalindrome(s1)) {
      string s2 = till_end(s, i);
      auto rec_ans = partition(s2);
      for(auto sub: rec_ans) {
        sub.insert(sub.begin(), s1);
        ans.push_back(sub);
      }
    }
  }
  return ans;
}
};
