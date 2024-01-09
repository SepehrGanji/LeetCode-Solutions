class Solution {
public:
    bool isPalindrome(string s) {
  if(s.length() <= 1) return true;
  string fin = "";
  for(int i = 0; i < s.length() ; i++) {
    char c = s[i];
    if(c >= 'a' && c <= 'z') fin += c;
    else if(c >= 'A' && c <= 'Z') fin += (c - 'A') + 'a';
    else if(c >='0' && c <= '9') fin +=c; 
  }
  // cout << fin << endl;
  if(fin.length() <= 1) return true;
  int p1 = 0, p2 = fin.length() - 1;
  while(p1 < p2) {
    if(fin[p1] != fin[p2]) return false;
    p1++;p2--;
  }
  return true;
}
};
