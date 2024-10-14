class Solution {
public:
    vector<int> root;
    
    int find(int i){
        if(root[i] == i) return i;
        return root[i] = find(root[i]);
    }
    
    void join(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if(root_i != root_j) {
            root[root_i] = root_j;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 0 ; i < n ; i++) root.push_back(i);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(isConnected[i][j]) join(i, j);
        
        set<int> ans;
        for(int i = 0 ; i < n ; i++) ans.insert(find(i));
        return ans.size();
    }
};
