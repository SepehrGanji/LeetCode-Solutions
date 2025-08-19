class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for(int i = 0 ; i < arr.size() ;) {
            bool found = false;
            int el = arr[i];
            for(int j = 0 ; j < pieces.size() ; j++) {
                if(el == pieces[j][0]) {
                    found = true;
                    for(int k = 0 ; k < pieces[j].size() ; k++) {
                        if(arr[i] != pieces[j][k]) return false;
                        i++;
                    }
                }
            }
            if(!found) return false;
        }
        return true;
    }
};
