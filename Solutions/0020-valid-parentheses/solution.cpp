class Solution {
public:
    bool isValid(string s) {
  stack<char> st;
  for(int i = 0 ; i < s.length() ; i++) {
    char c = s[i];
    if(c == '(' || c == '{' || c =='[') st.push(c);
    else if(st.size() == 0) return false;
    else if(c == ')') {
      if(st.top() != '(') return false;
      st.pop();
    } else if (c == '}') {
      if(st.top() != '{') return false;
      st.pop();
    } else if (c == ']') {
      if(st.top() != '[') return false;
      st.pop();
    }
  }
  return st.size() == 0;
}
};
