class Solution {
public:
    bool isValid(string a, string b) {
        int diff = 0;
        for(int i = 0 ; i < 8 ; i++) if(a[i] != b[i]) diff++;
        return diff == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        vector<bool> visited(n, false);
        queue<pair<string, int>> q;
        q.push(make_pair(startGene, 0));
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            string gene = curr.first;
            int level = curr.second;
            if(gene == endGene) return level;
            for(int i = 0 ; i < bank.size() ; i++) {
                if(!visited[i] && isValid(gene, bank[i])) {
                    visited[i] = true;
                    q.push(make_pair(bank[i], level+1));
                }
            }
        }
        return -1;
    }
};
