class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> pfx(n, 30000);
        vector<int> sfx(n, 30000);
        
        if(seats[0] == 1) pfx[0] = 0;
        for(int i = 1 ; i < n ; i++) {
            if(seats[i] == 1) pfx[i] = 0;
            else pfx[i] = pfx[i-1] + 1;
        }
        
        if(seats[n-1] == 1) sfx[n-1] = 0;
        
        for(int i = n-2 ; i >= 0 ; i--) {
            if(seats[i] == 1) sfx[i] = 0;
            else sfx[i] = sfx[i+1] + 1;
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++) ans = max(ans, min(pfx[i], sfx[i]));
        return ans;
    }
};
