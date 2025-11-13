#define ll long long

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int hcnt = 1;
        int vcnt = 1;
        ll ans = 0;
        while(!vc.empty() || !hc.empty())
        {
            ll vcurr = -1;
            ll hcurr = -1;
            
            if(!vc.empty()) 
                vcurr = vc.back(); // highest vertical cut available.
            
            if(!hc.empty()) 
                hcurr = hc.back(); // Highest horizontal cut available.
              
            
            if(vcurr>=hcurr) // vertical cut is the highest available.
            {
                vc.pop_back();
                
                ans += vcurr*hcnt;
                ++vcnt;
            }
            
            else // horizontal cut is the highest available.
            {
                hc.pop_back();
                
                ans += hcurr*vcnt;
                ++hcnt;
            }
        }
        
        return ans;
    }
};



