class Solution {
public:
    int ans;
    vector<vector<int>> gr;
    
    int iter(int el, int parent) {
        // if(gr[el].size() == 1) {
        //     ans++;
        //     return 1;
        // }
        vector<int> arr;
        for(auto node: gr[el]) 
            if(node != parent)
                arr.push_back(iter(node, el));
        
        bool yay = true;
        for(int i = 1 ; i < arr.size() ; i++) if(arr[i] != arr[0]) yay = false;
        if(yay) ans++;
        int su = 0;
        for(auto mmd: arr) su += mmd;
        return su+1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        gr.resize(100000);
        for(auto el: edges) {
            int a = el[0], b = el[1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        iter(0, -1);
        return ans;    
    }
};
