class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(start[i] == 'X') cnt++;
            if(result[i] == 'X') cnt--;
        }
        if(cnt != 0) return false;

        int i = 0 , j = 0;
        while(i < n && j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && result[j] == 'X') j++;
            if (i == n || j == n)
                return i == n && j == n;

            if (start[i] != result[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            
            i++;
            j++;
        }
        return true;
    }
};
