class Solution {
public:
    string delete_idx(string s, int idx) {
  string fin = "";
  for(int i = 0 ; i < s.length(); i++) {
    if(i != idx) fin += s[i];
  }
  return fin;
}

bool isPalindrome(string s) {
  if(s.length() <= 1) return true;
  string fin = s;
  if(fin.length() <= 1) return true;
  int p1 = 0, p2 = fin.length() - 1;
  while(p1 < p2) {
    if(fin[p1] != fin[p2]) return false;
    p1++;p2--;
  }
  return true;
}

bool validPalindrome(string s) {
  if(s.length() <= 2) return true;
  string fin = "";
  for(int i = 0; i < s.length() ; i++) {
    char c = s[i];
    if(c >= 'a' && c <= 'z') fin += c;
    else if(c >= 'A' && c <= 'Z') fin += (c - 'A') + 'a';
    else if(c >='0' && c <= '9') fin +=c;
  }
  if(fin.length() <= 2) return true;
  int p1 = 0, p2 = fin.length() - 1;
  bool del = false;
  while(p1 < p2) {
    if(fin[p1] != fin[p2]) {
      return isPalindrome(delete_idx(fin, p1)) || isPalindrome(delete_idx(fin, p2));
    }
    p1++;p2--;
  }
  return true;
}
};
