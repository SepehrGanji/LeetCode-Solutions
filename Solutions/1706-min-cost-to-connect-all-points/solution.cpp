class Solution {
public:
    typedef pair<int, int> pii;
    map<pii, pii> un;
    
    int dist(pii a, pii b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    pii getParent(pii a) {
        if(un[a] == a) return a;
        un[a] = getParent(un[a]);
        return un[a];
    }

    void join(pii a, pii b) {
        auto para = getParent(a);
        auto parb = getParent(b);
        un[para] = parb;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<pii, pii>>> edges;
        int n = points.size();
        
        for(int i = 0 ; i < n ; i++) {
            pii a = pii(points[i][0], points[i][1]);
            un[a] = a;
            for(int j = i+1 ; j < n ; j++) {
                pii b = pii(points[j][0], points[j][1]);
                edges.push_back(make_pair(dist(a, b), make_pair(a, b)));
            }
        }
        sort(edges.begin(), edges.end());
        int added = 0;
        int ans = 0;
        int ptr = 0;
        while(added < n-1) {
            auto edge = edges[ptr++];
            int wei = edge.first;
            pii a = edge.second.first;
            pii b = edge.second.second;
            if(getParent(a) != getParent(b)) {
                join(a, b);
                added++;
                ans += wei;
            }
        }
        return ans;
    }
};
