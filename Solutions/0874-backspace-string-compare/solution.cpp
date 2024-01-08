class Solution {
public:
    bool backspaceCompare(string s, string t) {
  int p1, p2;
  p1 = s.length() - 1;
  p2 = t.length() - 1;
  int ts1 = 0, ts2 = 0;
  while(p1 >= 0 || p2 >= 0) {
    char e1 = p1 >= 0 ? s[p1] : '.';
    char e2 = p2 >= 0 ?  t[p2] : '.';
    if(e1 == '#') {
      ts1++;
      p1--;
    } else if (e2 == '#') {
      ts2++;
      p2--;
    } else if(ts1 > 0) {
      ts1--; p1--;
    } else if(ts2 > 0) {
      ts2--; p2--;
    } else {
      //cout << "e1e2" << e1 << e2 << endl;
      if(e1 != e2) return false;
      p1--;p2--;
    }
  }
  //cout << "p1: " << p1 << " & p2: " << p2 << endl;
  return p1 < 0 && p2 < 0;
}
};
