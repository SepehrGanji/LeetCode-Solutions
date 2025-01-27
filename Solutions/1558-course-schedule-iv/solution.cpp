class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> gr(numCourses);
        for(auto pr: prerequisites) {
            int a = pr[0], b = pr[1];
            gr[a].push_back(b);
        }
        vector<vector<bool>> rc(numCourses, vector<bool>(numCourses, false));
        //
        for(int i = 0 ; i < numCourses ; i++) {
            queue<int> q;
            //vector<bool> visited(numCourses, false);
            q.push(i);
            while(!q.empty()) {
                int node = q.front(); q.pop();
                for(auto nei: gr[node]) {
                    if(!rc[i][nei]) {
                        rc[i][nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        //
        vector<bool> ans;
        for(int i = 0 ; i < queries.size() ; i++) {
            int a = queries[i][0], b = queries[i][1];
            ans.push_back(rc[a][b]);
        }
        return ans;
    }
};
