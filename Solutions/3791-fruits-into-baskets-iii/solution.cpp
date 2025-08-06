class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        float en = n;
        int bsize = ceil(sqrt(n));
        int nob = ceil(en / bsize);
        cout << bsize << ' ' << nob << endl;
        
        vector<int> maxs;

        for(int i = 0 ; i < nob ; i++) {
            int maxi = -1;
            for(int j = i * bsize ; j < min((i+1) * bsize, n) ; j++) {
                maxi = max(maxi, baskets[j]);
            }
            maxs.push_back(maxi);
        }
        int ans = 0;
        for(auto el: fruits) {
            bool placed = false;
            for(int i = 0 ; i < nob ; i++) {
                if(maxs[i] >= el) {
                    int maxi = -1;
                    for(int j = i * bsize ; j < min((i+1) * bsize, n) ; j++) {
                        if(!placed && baskets[j] >= el) {
                            baskets[j] = 0;
                            placed = true;
                        }
                        maxi = max(maxi, baskets[j]);
                    }
                    maxs[i] = maxi;
                    break;
                }   
            }
            if(!placed) ans++;
        }
        
        return ans;
    }
};
