class Solution {
    vector<vector<int>> gr;
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        gr.resize(50005);
        for(int i = 0 ; i < n ; i++) {
            int process = pid[i];
            int parent = ppid[i];
            gr[parent].push_back(process);
        }
        vector<int> ans;
        stack<int> st;
        st.push(kill);
        while(!st.empty()) {
            int el = st.top(); st.pop();
            ans.push_back(el);
            for(auto mmd: gr[el]) st.push(mmd);
        }
        return ans;
    }
};
