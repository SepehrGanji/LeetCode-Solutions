class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int m = pieces.size();
        int i = 0;
        while(i < n) {
            bool found = false;
            for(int j = 0 ; j < m ; j++) {
                if(arr[i] == pieces[j][0]) {
                    found = true;
                    int k = pieces[j].size();
                    for(int kk = 0 ; kk < k ; kk++) {
                        if(arr[i] != pieces[j][kk]) return false;
                        i++;
                    }
                }
                if(i >= n) break;
            }
            if(!found) return false;
        }
        return true;
    }
};
