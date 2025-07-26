class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int a1 = 0, a2 = 0, a3 = 0;
        int n = seats.size();
        int s = -1, e = -1;
        for(int i = 0 ; i < n ; i++) {
            if(seats[i] == 0) a1++;
            else {
                s = i;
                break;
            }
        }
        for(int i = n-1 ; i>= 0 ; i--) {
            if(seats[i] == 0) a3++;
            else {
                e = i;
                break;
            }
        }
        int len = 0;
        int max_len = 0;
        for(int i = s ; i <= e ; i++) {
            if(seats[i] == 0) len++;
            else {
                max_len = max(max_len, len);
                len = 0;
            }
        }
        a2 = ceil(max_len / 2.0);
        return max(a1, max(a2, a3));
    }
};
