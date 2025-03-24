class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1;
        int A = fruits[0], fst_A = 0, lst_A = 0;
        int B = -1, fst_B = -1, lst_B = -1;
        
        int l = 0, r = 1; // r is the next candiate
        while(r < fruits.size()) {
            int cf = fruits[r];
            if(cf == A || cf == B) {
                if(cf == A) lst_A = r;
                else lst_B = r;
                
                ans = max(ans, r-l+1);
                r++;
            } else {
                if(B == -1) {
                    B = cf;
                    // fst_B = r;
                    lst_B = r;
                    ans = max(ans, r-l+1);
                    r++;
                } else {
                    if(lst_A < lst_B) {
                        // replace A, window now is containing B
                        l = lst_A + 1;
                        A = cf;
                        lst_A = r;
                        ans = max(ans, r-l+1);
                        r++;
                    } else {
                        l = lst_B + 1;
                        B = cf;
                        lst_B = r;
                        ans = max(ans, r-l+1);
                        r++;
                    }
                }
            }
        }
        return ans;
    }
};
