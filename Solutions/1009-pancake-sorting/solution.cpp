class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int fixed = n;
        while(fixed > 0) {
            int maxi = arr[0], maxidx = 0;
            for(int i = 0 ; i < fixed ; i++)
                if(arr[i] > maxi) {
                    maxi = arr[i];
                    maxidx = i;
                }
            
            if(maxidx > 0) {
                // first flip
                ans.push_back(maxidx+1);
                reverse(arr.begin(), arr.begin() + maxidx+1); // included?!
            }
            // second flip
            ans.push_back(fixed);
            reverse(arr.begin(), arr.begin() + fixed);  // included?!
            fixed--;
        }
        return ans;
    }
};
