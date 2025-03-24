class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == 0 && i < n - 1) {
                int reserve = arr[i+1];
                for(int j = i + 2 ; j < n ; j++) {
                    int next_reserver = arr[j];
                    arr[j] = reserve;
                    reserve = next_reserver;
                }
                arr[i+1] = 0;
                i++;
            }
        }
    }
};
