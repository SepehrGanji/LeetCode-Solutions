class UnionFind{
private:
    vector<int> par;
    int n;
public:
    UnionFind(int en) {
        n = en;
        for(int i = 0 ; i < n ; i++) par.push_back(i);
    }

    int find(int x) {
        while(par[x] != x) x = par[x];
        return x;
    }

    void connect(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if(pi < pj) par[pj] = pi;
        else par[pi] = pj;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // 0 and 1 based
        UnionFind uf(c);
        for(auto coco: connections) {
            int i = coco[0] - 1, j = coco[1] - 1;
            uf.connect(i, j);
        }
        vector<set<int>> arr;
        arr.resize(c);
        for(int i = 0 ; i < c ; i++) {
            int pa = uf.find(i);
            arr[pa].insert(i);
        }

        vector<int> ans;
        for(auto q: queries) {
            int qt = q[0], qel = q[1] - 1;
            int pa = uf.find(qel);
            if(qt == 1) {
                // check
                if(arr[pa].empty()) ans.push_back(-1);
                else if(arr[pa].find(qel) != arr[pa].end()) ans.push_back(qel+1);
                else {
                    int smallest = *arr[pa].begin();
                    ans.push_back(smallest+1);
                }
            } else {
                // offline
                arr[pa].erase(qel);
            }
        }
        
        return ans;
    }
};
