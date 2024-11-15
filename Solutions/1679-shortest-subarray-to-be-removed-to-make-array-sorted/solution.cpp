class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        if(n == 2) return arr[0] < arr[1] ? 0 : 1;
        int l = 1, r = n-2;
        while(l < n && arr[l] >= arr[l-1]) l++;
        while(r >= 0 && arr[r] <= arr[r+1]) r--;
        cout << "l: " << l << " && r: " << r << endl;
        l--; r++;
        if(l > r) return 0;
        
        int ans = max(l+1, n-r);
        
        for(int i = 0 ; i <= l ; i++) {
            int el = arr[i];
            // bin search between arr[r], arr[n], where I can continue this subarray???
            int lef = r, rig = n;
            while(lef < rig) {
                int mid = (lef+rig) / 2;
                if(arr[mid] < el) lef=mid+1;
                else rig = mid;
            }
            // (0-i+1), (n-righ)
            ans = max(ans, i+1+n-rig);
        }
        return n-ans;
    }
};
